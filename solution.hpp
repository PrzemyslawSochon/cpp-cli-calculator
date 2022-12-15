#pragma once
#include <string>
#include <string_view>

struct SignificantExpr
{
    std::string value1;
    char symbol{'+'};
    std::string value2{0};
};

SignificantExpr parenthesis(const std::string &str);
SignificantExpr binaryOperators(const std::string &str);
double results(SignificantExpr expr);