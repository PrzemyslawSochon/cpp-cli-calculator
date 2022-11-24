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

#endif //!INPUT_HPP