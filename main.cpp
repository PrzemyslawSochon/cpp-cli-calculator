#include "input.hpp"
#include <algorithm>
#include <iostream>
#include <string>

std::string filterWhitespace(const std::string& str)
{
    auto is_ws = [](char c)
    {
        return std::isspace(c);
    };
    std::string copy{str};
    copy.erase(std::remove_if(copy.begin(), copy.end(), is_ws), copy.end());

    return copy;
}

int main()
{
    std::string dinput{};
    std::cin >> dinput;
    std::cout << filterWhitespace(dinput);
    return 0;
}