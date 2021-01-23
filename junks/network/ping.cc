#include <vector>
#include <iostream>
#include <cstring>
#include <cstdio>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

namespace
{
    // https://www.geekpage.jp/programming/linux-network/simple-ping.php
    unsigned short checksum(unsigned short *buf, int bufsz)
    {
        unsigned long sum = 0;

        while (bufsz > 1)
        {
            sum += *buf;
            buf++;
            bufsz -= 2;
        }

        if (bufsz == 1)
        {
            sum += *(unsigned char *)buf;
        }

        sum = (sum & 0xffff) + (sum >> 16);
        sum = (sum & 0xffff) + (sum >> 16);

        return ~sum;
    }

    class FileDesc
    {
    public:
        FileDesc(int fd) : fd_(fd) {}
        ~FileDesc()
        {
            close(fd_);
        }

        operator int() const { return fd_; }

    private:
        int fd_;
    };
} // namespace

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::fprintf(stderr, "usage : %s [addr]\n", argv[0]);
        return 1;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    int fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (fd < 0)
    {
        std::perror("socket");
        return 1;
    }
    FileDesc sock(fd);

    std::vector<char> buf(2000);

    // ICMPパケットの送信
    std::string body = "hello world";
    auto *hdr = reinterpret_cast<struct icmphdr *>(&buf[0]);
    auto hdrsize = sizeof(struct icmphdr);
    memset(hdr, 0, hdrsize);
    hdr->type = ICMP_ECHO;
    hdr->code = 0;
    hdr->checksum = 0;
    hdr->un.echo.id = getpid();
    hdr->un.echo.sequence = 0;
    std::copy(body.begin(), body.end(), buf.begin() + hdrsize);
    auto packsize = hdrsize + body.size();
    hdr->checksum = checksum((unsigned short *)&buf[0], packsize);

    auto nw = sendto(sock, &buf[0], packsize, 0, (struct sockaddr *)&addr, sizeof(addr));
    if (nw < 1)
    {
        std::perror("sendto");
    }

    // ICMP ECHO REPLYの受信
    struct iphdr *iphdrptr;
    while (1)
    {
        auto nr = recv(sock, &buf[0], buf.size(), 0);
        if (nr < 1)
        {
            std::perror("recv");
        }
        iphdrptr = reinterpret_cast<struct iphdr *>(&buf[0]);
        if (iphdrptr->protocol = 1)
            break;
    }

    auto icmphdrptr = reinterpret_cast<struct icmphdr *>(&buf[0] + (iphdrptr->ihl * 4));
    if (icmphdrptr->type == ICMP_ECHOREPLY)
    {
        std::fprintf(stderr, "received ICMP ECHO REPLY\n");
    }
    else
    {
        std::fprintf(stderr, "received ICMP %d\n", icmphdrptr->type);
    }

    return 0;
}