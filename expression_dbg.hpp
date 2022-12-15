#pragma once

#include <algorithm>
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

// Before, we can work mathematically with the expression, firstly, we need to debug user input.
// It's split into two parts: simplification and error search.
// Simplification is performed without user intervention.
// It cleans up obsolete characters and makes expressions friendly for further analysis.
// Error search looks for input ambiguity or operations that are impossible to solve.
// If found, a user is asked to correct the input and try again.

// Generally, simplification is performed first for the sake of source code simplicity.
// I.e. I don't have to deal with whitespaces if I remove them in the first place.

inline void printMathExpression(std::string_view str)
{
    if (std::cout << str << '\n')
    {
        return;
    }
}

std::string consoleInputDebug();

bool confirm();

inline void trimWhiteSpaces(std::string &str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

inline bool isAlphanumeric(char c)
{
    return (c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

std::string_view debugRepeatingSigns(std::string &str);
std::string_view debugDoubleAsterisks(std::string &str);
std::string_view debugCommas(std::string &str);
std::string_view debugBrackets(std::string &str);
std::string_view debugBackSlash(std::string &str);
std::string_view debugPercentSign(std::string &str);
std::string_view debugExclamation(std::string &str);
std::string_view debugLiterals(std::string &str);
std::string_view debugBracketAdjacentSymbols(std::string &str);
std::string_view debugNonAsciiChars(std::string &str);

Brackets areBracketsPaired(std::string_view str);
Brackets areBracketsEncapsulated(std::string_view str);