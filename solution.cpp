#include "expression_dbg.hpp"
#include "settings.hpp"
#include "solution.hpp"
#include "stream_dbg.hpp"
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>

struct IndividualExpression
{
    std::string value1{};
    char operation{};
    std::string value2{};
};

std::string copyValueFromLeft(int pos, std::string str)
{
    // might be reasonable to put assertion here
    // in case of pos==0
    for (int i{pos}; i >= -1; --i)
    {
        if (i == -1 || isEFRMD(str[i]))
        {
            int length{pos - i - 2};
            return str.substr(i + 1, length);
        }
    }
}

std::string copyValueFromRight(int pos, std::string str)
{
    // same as above, in case of pos==str.back
    for (int i{pos}; i <= str.size(); ++i)
    {
        if (i == str.size() || isERMDAS(str[i]))
        {
            int length{pos - i - 2};
            return str.substr(pos + 1, length);
        }
    }
}

double calculate(IndividualExpression expr)
{
    double value1{std::stod(expr.value1)};
    double value2{std::stod(expr.value2)};
    switch (expr.operation)
    {
    case '^':
        return std::pow(value1, value2);
    case '%':
        return std::fmod(value1, value2);
    case '*':
        return value1 * value2;
    case '/':
        return value1 / value2;
    case '+':
        return value1 + value2;
    case '-':
        return value1 - value2;
    default:
        assert(expr.operation && "Unrecognized operation");
    }
}

std::string copyMostSignificantParent(std::string str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] == ')')
        {
            for (int j{i}; j >= -1; --j)
            {
                if (j == -1)
                {
                    assert(j && "Closed bracket not found, debug probably broken");
                }
                if (str[j] == '(')
                {
                    int length{i - j - 2};
                    return str.substr(j + 1, length);
                }
            }
        }
    }
    // there's no parenthesis left, return an empty string
    return "";
}

void solveMostSignificantOperator(std::string &str)
{
    IndividualExpression expr{0, '+', 0};
    for (int i{0}; i < str.size(); ++i)
    {
        char operation{str[i]};
        switch (operation)
        {
        case '^':
        {
            expr = {
                copyValueFromLeft(i, str),
                '^',
                copyValueFromRight(i, str)};
        }
        case '%':
        {
            expr = {
                copyValueFromLeft(i, str),
                '%',
                copyValueFromRight(i, str)};
        }
        case '*':
        {
            expr = {
                copyValueFromLeft(i, str),
                '*',
                copyValueFromRight(i, str)};
        }
        case '/':
        {
            expr = {
                copyValueFromLeft(i, str),
                '/',
                copyValueFromRight(i, str)};
        }
        default:
            continue;
        }

        double result{calculate(expr)};

        std::string str_result{std::to_string(result)};

        int begin_position{i - expr.value1.length()};
        int length_to_swap{
            expr.value1.length() + expr.value2.length() + 1};

        str.erase(begin_position, length_to_swap);
        str.insert(begin_position, str_result);
        i = -1;
    }
}