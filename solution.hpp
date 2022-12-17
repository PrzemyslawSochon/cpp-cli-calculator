#pragma once
#include <string>

struct IndividualExpression
{
    std::string value1{};
    char operation{};
    std::string value2{};
};

std::string copyValueFromLeft(int pos, std::string str);
std::string copyValueFromRight(int pos, std::string str);
double calculate(IndividualExpression expr);
std::string copyMostSignificantParent(std::string str);
void solveMostSignificantOperator(std::string &str);
