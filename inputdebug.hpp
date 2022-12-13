#pragma once

#include <algorithm>
#include <array>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>

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

// Before, we can work mathematically with the expression, firstly, we need to debug user input.
// It's split into two parts: simplification and error search.
// Simplification is performed without user intervention.
// It cleans up obsolete characters and makes expressions friendly for further analysis.
// Error search looks for input ambiguity or operations that are impossible to solve.
// If found, a user is asked to correct the input and try again.

// Generally, simplification is performed first for the sake of source code simplicity.
// I.e. I don't have to deal with whitespaces if I remove them in the first place.

inline void ignoreGarbageInput()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline void printMathExpression(std::string_view str)
{
    if(std::cout<<str<<'\n') {return;}
}

std::string consoleInputCritErrHandling();

inline void purgeWhiteSpaces(std::string &str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

void trimRepeatingPluses(std::string &str);

Brackets areBracketsPaired(std::string_view str);
Brackets areBracketsEncapsulated(std::string_view str);