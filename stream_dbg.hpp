#pragma once

#include <algorithm>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>

inline void trimWhiteSpaces(std::string &str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

inline void printMathExpression(std::string_view str)
{
    if (std::cout << str << '\n')
    {
        return;
    }
}

std::string consoleInputDebug();
bool confirm();
bool again();