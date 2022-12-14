#include "solution.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' || c == '!';
}

SignificantExpr parenthesis(std::string &str)
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

SignificantExpr binaryOperators(std::string &str)
{
    std::string value1;
    char symbol{'+'};
    std::string value2{0};
    for (int i{0}; i <= str.size(); ++i)
    {
        if (isOperator(str[i]))
        {
            symbol=str[i];
            for (int j{i-1}; j >= 0; --j)
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

StringPosition extractFromParenthesis(const std::string &str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] == ')')
        {
            for (int j{i}; j > -1; --j)
            {
                if (str[j] == '(')
                {
                    return {str.substr(j + 1, i - j - 1), j, i};
                }
            }
            assert(str[i] && "No closing bracket!");
        }
    }
    return {"error", -1, -1};
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
        case '^':
        case '%':
        {
            double variable1{(std::stod(str.substr(0, i + 1)))};
            double variable2{(std::stod(str.substr(i + 1)))};
            char symbol{str[i]};
            return {variable1, variable2, symbol};
        }
        }
    }
    return {0, 0, '0'};
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
    case '^':
    {
        return (pow(ex.variable1, ex.variable2));
    }
    case '%':
    {
        return (fmod(ex.variable1, ex.variable2));
    }
    default:
    {
        assert(ex.symbol && "Operator not found!");
    }
    }
    return EXIT_FAILURE;
}

void insertResultToExpression(std::string &expr, double result, int pos1, int pos2)
{
    expr.erase(pos1, pos2 - pos1 + 1);
    expr.insert(pos1, std::to_string(result));
}