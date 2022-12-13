#pragma once
#ifndef INPUT_HPP
#define INPUT_HPP

#include <ios>
#include <iostream>
#include <limits>

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

inline void ignoreExtraInput()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif //!INPUT_HPP