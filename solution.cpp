#include "settings.hpp"
#include "solution.hpp"
#include <array>
#include <cassert>
#include <cmath>

std::string copyValueFromLeft(int pos, std::string str)
{
    // might be reasonable to put assertion here
    // in case of pos==0

    for (int i{pos - 1}; i >= -1; --i)
    {
        if (i == -1 || isERMD(str[i]))
        {
            std::cout << "left i: " << i << " left pos " << pos << '\n';
            int length{pos - i - 1};
            std::cout << "left value len " << length << '\n';
            return str.substr(i + 1, length);
        }
    }
    assert(pos && "Integer overflow probably");
    return "";
}

std::string copyValueFromRight(int pos, std::string str)
{
    // same as above, in case of pos==str.back

    for (int i{pos + 1}; i <= str.size(); ++i)
    {
        if (i == str.size() || isERMD(str[i]))
        {
            std::cout << "Right i: " << i << " right pos " << pos << '\n';
            int length{i - pos - 1};
            std::cout << "right value len " << length << '\n';
            return str.substr(pos + 1, length);
        }
    }
    assert(pos && "Integer overflow probably");
    return "";
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
        return 0;
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

    for (const char &operation : order_of_operations)
    {
        //reasonable default state, solution to that equals 0
        IndividualExpression expr{"0", '+', "0"};

        for (int i{0}; i < str.size(); ++i)
        {
            if (str[i] == operation)
            {
                expr = {
                    copyValueFromLeft(i, str),
                    operation,
                    copyValueFromRight(i, str)};
                double result{calculate(expr)};

                std::string str_result{std::to_string(result)};

                int begin_position{i - static_cast<int>(expr.value1.length())};
                std::cout << begin_position << '\n';
                int length_to_swap{
                    static_cast<int>(expr.value1.length()) + static_cast<int>(expr.value2.length())};

                str.erase(begin_position, length_to_swap);
                str.insert(begin_position, str_result);
                i = -1;
            }
        }
    }
}