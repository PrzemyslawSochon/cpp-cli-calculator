#pragma once

#include <algorithm>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>

// note ASCII only
inline bool isAlphanumeric(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

inline bool isAnyOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' || c == '!');
}

// exponent, remainder, multiplication, division, addition, subtraction
inline bool isERMDAS(char c)
{
    return (c == '^' || c == '%' || c == '*' || c == '/' || c == '+' || c == '-');
}

// exponent, factorial, remainder, multiplication, division
inline bool isEFRMD(char c)
{
    return (c == '^' || c == '!' || c == '%' || c == '*' || c == '/');
}

// exponent, remainder, multiplication, division
inline bool isERMD(char c)
{
    return (c == '^' || c == '%' || c == '*' || c == '/');
}

inline bool areParentsStillAround(std::string_view str)
{
    for (const auto &c : str)
    {
        if (c == ')')
        {
            return true;
        }
    }
    return false;
}

// Before, we can work mathematically with the expression, firstly, we need to debug user input.
// It's split into two parts: simplification and error search.
// Simplification is performed without user intervention.
// It cleans up obsolete characters and makes expressions friendly for further analysis.
// Error search looks for input ambiguity or operations that are impossible to solve.
// If found, a user is asked to correct the input and try again.

// Generally, simplification is performed first for the sake of source code simplicity.
// I.e. I don't have to deal with whitespaces if I remove them in the first place.

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
std::string_view debugAdjacentOperators(std::string &str);

std::string_view areBracketsPaired(std::string_view str);
std::string_view areBracketsEncapsulated(std::string_view str);