#include "solution.hpp"
#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

std::string_view extractFromParenthesis(std::string_view str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] == ')')
        {
            for (int j{0}; j > -1; --j)
            {
                if (str[j] == '(')
                {
                    return str.substr(i - j + 1, j - 2);
                }
            }
            assert(str[i] && "No closing bracket!");
        }
    }
}

Expression turnStringIntoExpression(const std::string &str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        switch (str[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
        {
            double variable1{static_cast<double>(std::stoi(str.substr(0, i + 1)))};
            double variable2{static_cast<double>(std::stoi(str.substr(i + 1)))};
            char symbol{static_cast<char>(str[i])};
            return {variable1, variable2, symbol};
        }
        }
    }
}

double calculateResultOfExpression(Expression ex)
{
    switch (ex.symbol)
    {
    case '+':
    {
        return (ex.variable1 + ex.variable2);
    }
    case '-':
    {
        return (ex.variable1 - ex.variable2);
    }
    case '/':
    {
        return (ex.variable1 / ex.variable2);
    }
    case '*':
    {
        return (ex.variable1 * ex.variable2);
    }
    default:
    {
        assert(ex.symbol && "Operator not found!");
    }
    }
}