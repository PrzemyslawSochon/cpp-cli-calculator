#pragma once
#ifndef INPUTDEBUG_HPP
#define INPUTDEBUG_HPP

#include <array>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

using x1x2scope = std::array<int, 2>;

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

//Before, we can work mathematically with equation, firstly, we need to debug user input.
//Its split into two parts: simplification and error search.
//Simplification is performed without user intervention.
//It cleanups obsolete characters and makes equation friendly for further analysis.
//Error search looks for input ambiguity or operations that are impossible to solve.
//If found, user is asked to correct input and try again.

//Generally, simplification is performed first for the sake of source code simplicity.
//I.e. I don't have to deal with whitespaces if I remove them in the first place.


inline void ignoreGarbageInput()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string consoleInputCritErrHandling();

inline void purgeWhiteSpaces(std::string &str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

void purgeRepeatingPluses(std::string &str);

Brackets areBracketsEven(const std::string &str);
Brackets areBracketsEncapsulated(const std::string &str);
void cancelRowOfSigns(std::string &str);
void cancelOutSigns(std::string &str);

#endif //! INPUTDEBUG_HPP