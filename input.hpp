#pragma once
#ifndef INPUT_HPP
#define INPUT_HPP

#include <ios>
#include <iostream>
#include <limits>

inline void ignoreExtraInput()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline void purgeWhiteSpaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

void purgeRepeatingPluses(std::string& str);


//x_scope can hold vector of coordinates such as [[1,2],[3,4],[10,12]]
using x_scope = std::array<int,2>;

enum class Brackets
{
    ok,

    err_odd_number,
    err_opening_absence,

    size
};

enum class Sign
{
    negative,
    positive,

    size
};

Brackets areBracketsEven(const std::string& str);
Brackets areBracketsEncapsulated(const std::string& str);
void cancelRowOfSigns(std::string& str);
void cancelOutSigns(std::string& str);

#endif //!INPUT_HPP