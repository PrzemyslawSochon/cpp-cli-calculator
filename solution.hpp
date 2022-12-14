#pragma once

struct Expression
{
    double variable1{1};
    double variable2{1};
    char symbol{};
};

std::string_view extractFromParenthesis(std::string_view str);

Expression turnStringIntoExpression(const std::string &str);

double calculateResultOfExpression(Expression ex);