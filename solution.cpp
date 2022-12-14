#include "settings.hpp"
#include "solution.hpp"
#include "stream_dbg.hpp"
#include <array>
#include <cassert>
#include <cmath>

std::string copyValueFromLeft(int pos, std::string str)
{

    for (int i{pos - 1}; i >= -1; --i)
    {
        if (i == -1 || isERMDAS(str[i]))
        {
            int length{pos - i - 1};
            if (str[i] == '-')
            {
                length = pos - i;
                return str.substr(i, length);
            }
            return str.substr(i + 1, length);
        }
    }
    assert(pos && "Integer overflow probably");
    return "";
}

std::string copyValueFromRight(int pos, std::string str)
{
    int i{pos + 1};
    if (i == '-')
    {
        int i{pos + 2};
    }
    for (; i <= str.size(); ++i)
    {
        if (i == str.size() || isERMDAS(str[i]))
        {
            int length{i - pos - 1};
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

    for (std::string_view operation : order)
    {
        // reasonable default state
        IndividualExpression expr{"0", '+', "0"};
        for (int i{1}; i < str.size(); ++i)
        {
            if (has_char(operation, str[i]))
            {
                expr = {
                    copyValueFromLeft(i, str),
                    str[i],
                    copyValueFromRight(i, str)};
                std::cout << "Left variable: " << expr.value1 << '\n';
                std::cout << "Operation : " << expr.operation << '\n';
                std::cout << "Right variable: " << expr.value2 << '\n';
                double result{calculate(expr)};
                std::cout << "Result: " << result << '\n';

                std::string str_result{removeTrailingZeros(result)};

                int begin_position{i - static_cast<int>(expr.value1.length())};
                int length_to_swap{
                    static_cast<int>(expr.value1.length()) + static_cast<int>(expr.value2.length() + 1)};

                str.erase(begin_position, length_to_swap);
                str.insert(begin_position, str_result);
                i = 0;
                std::cout << "Now expression looks like: " << str << '\n';
            }
        }
    }
}