#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>
#include <vector>
#include <iostream>
#include <cstring>
#include <atomic>
#include <thread>

namespace
{
    const std::size_t BUFFER_SIZE = 1024;

    std::atomic<bool> running;
} // namespace

class Handler
{
public:
    Handler(int fd) : fd_(fd), buf_(BUFFER_SIZE) {}

    void operator()()
    {
        while (1)
        {
            int nread = recv(fd_, &buf_[0], buf_.size(), 0);
            if (!nread)
                break;
            if (nread < 0)
            {
                std::cerr << std::strerror(errno) << std::endl;
                break;
            }

            int err = send(fd_, &buf_[0], nread, 0);
            if (err < 0)
            {
                std::cerr << std::strerror(errno) << std::endl;
                break;
            }
        }
    }

private:
    int fd_;
    std::vector<char> buf_;
};

void signal_handler(int signum)
{
    running = false;
}

int main(int argc, char *argv[])
{
    struct sigaction action;
    action.sa_handler = signal_handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " [port]" << std::endl;
        std::exit(1);
    }

    int port = atoi(argv[1]);

    struct sockaddr_in server, client;
    std::vector<char> buf(BUFFER_SIZE);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        std::cerr << std::strerror(errno) << std::endl;
        std::exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    int opt_val = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof(opt_val));

    int err = bind(server_fd, (struct sockaddr *)&server, sizeof(server));
    if (err < 0)
    {
        std::cerr << std::strerror(errno) << std::endl;
        std::exit(1);
    }

    err = listen(server_fd, 128);
    if (err < 0)
    {
        std::cerr << std::strerror(errno) << std::endl;
        std::exit(1);
    }

    std::cout << "server is listening on " << port << std::endl;

    running = true;
    while (running)
    {
        socklen_t client_len = sizeof(client);
        int client_fd = accept(server_fd, (struct sockaddr *)&client, &client_len);
        if (client_fd < 0)
        {
            std::cerr << std::strerror(errno) << std::endl;
            running = false;
            break;
        }
        auto th = std::thread(Handler(client_fd));
        th.detach();
    }
    std::cerr << "server exitting" << std::endl;
    close(server_fd);

    return 0;
}