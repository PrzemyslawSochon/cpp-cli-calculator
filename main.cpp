#include "input.hpp"
#include <algorithm> //for std::remove_if
#include <array>
#include <string>
#include <vector>

inline void purgeWhiteSpaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

int main()
{
    std::cout << "Enter the expression: ";
    std::string expression{};
    std::getline(std::cin, expression);

    purgeWhiteSpaces(expression);
    std::cout << expression << '\n';

    areBracketsEven(expression);
    areBracketsEncapsulated(expression);
    cancelOutSigns(expression);

    return 0;
}