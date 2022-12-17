#pragma once
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <string_view>

constexpr std::array <char, 4>
order_of_operations{'^', '%', '*', '/'};

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

namespace mathConstants
{
    constexpr double pi_value{3.14159};
    constexpr double e_value{2.71828};
    constexpr std::string_view pi_str{"3.14159"};
    constexpr std::string_view e_str{"2.71828"};
}

// if any of the following booleans is set to false
// program will throw an error on a corresponding encounter
constexpr bool g_verbose{true};
constexpr bool g_treat_double_asterisks_as_exponent{true};
constexpr bool g_treat_comma_as_decimal_fraction{true};
constexpr bool g_treat_all_brackets_as_parenthesis{false};
constexpr bool g_treat_backward_slash_as_division{true};
constexpr bool g_treat_exclamation_as_factorial{true};
constexpr bool g_treat_parenthesis_adjacent_symbols_as_multiplication{true};

constexpr bool g_treat_pi_as_constant{true};
constexpr bool g_treat_e_as_constant{true};

constexpr bool g_trim_non_ascii_chars{true};

// only one of them can be true, if user forces both to be true
// XOR will throw 0
constexpr bool g_treat_percentage_as_modulo{false};
constexpr bool g_treat_percentage_as_decimal{true};
constexpr bool g_xor_percentage{
    g_treat_percentage_as_modulo ^ g_treat_percentage_as_decimal};