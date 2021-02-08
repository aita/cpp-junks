#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

int main() {
    std::vector<std::string> buf;

    boost::split(buf, "a,b,c", boost::is_any_of(","));
    for (const auto& str: buf) {
        std::cout << str << std::endl;
    }

    boost::split(buf, "12 33 dc", boost::is_space());
    for (const auto& str: buf) {
        std::cout << str << std::endl;
    }

    return 0;
}
