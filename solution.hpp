#pragma once
#include <string>
#include <string_view>

struct SignificantExpr
{
    std::string value1;
    char symbol{'+'};
    std::string value2{0};
};

/* struct Expression
{
    double variable1{1};
    double variable2{1};
    char symbol{'$'};
};

struct StringPosition
{
    std::string str{};
    int x1 {};
    int x2 {};
}; */

/* StringPosition extractFromParenthesis(const std::string& str);

Expression turnStringIntoExpression(const std::string &str);

double calculateResultOfExpression(Expression ex); */

void insertResultToExpression(std::string& expr, double result, int pos1, int pos2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      