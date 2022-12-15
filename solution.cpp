#include "solution.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' || c == '!';
}

SignificantExpr parenthesis(const std::string &str)
{
    std::string value1;
    char symbol{'+'};
    std::string value2{0};
    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] == ')')
        {
            for (int j{i - 1}; j >= 0; --j)
            {
                if (str[j] == '(')
                {
                    for (int k{j + 1}; k < str.size(); ++k)
                    {
                        if (isOperator(str[k]))
                        {
                            // we've got everything, begin extraction
                            value1 = str.substr(j + 1), k - j - 1;
                            symbol = str[k];
                            value2 = str.substr(k + 1), i - k - 1;
                        }
                        else if (str[k] == ')')
                        {
                            value1 = str.substr(j + 1), i - j - 1;
                        }
                    }
                    return {value1, symbol, value2};
                }
            }
        }
    }
}

SignificantExpr binaryOperators(const std::string &str)
{
    std::string value1;
    char symbol{'+'};
    std::string value2{0};
    for (int i{0}; i <= str.size(); ++i)
    {
        if (isOperator(str[i]))
        {
            symbol=str[i];
            for (int j{i-1}; j >= 0; ++j)
            {
                if (isOperator(str[j]))
                {
                    value1 = str.substr(j + 1, i - j - 1);
                }
            }
            for (int k{i+1}; k <= str.size(); ++k)
            {
                if (isOperator(str[k]))
                {
                    value2 = str.substr(i + 1, k - i - 1);
                }
            }
            return{value1, symbol, value2};
        }
    }
}

double results(SignificantExpr expr)
{
    double value1{std::stod(expr.value1)};
    char symbol{expr.symbol};
    double value2{std::stod(expr.value2)};

    switch (symbol)
    {
    case '+':
    {
        return (value1 + value2);
    }
    case '-':
    {
        return (value1 - value2);
    }
    case '/':
    {
        return (value1 / value2);
    }
    case '*':
    {
        return (value1 * value2);
    }
    case '^':
    {
        return (pow(value1, value2));
    }
    case '%':
    {
        return (fmod(value1, value2));
    }
    default:
    {
        assert(symbol && "Operator not found!");
    }
    }
}