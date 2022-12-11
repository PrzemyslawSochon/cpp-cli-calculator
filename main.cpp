#include "input.hpp"
#include <algorithm> //for std::remove_if

std::string purgeWhiteSpaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
    return str;
}


int main()
{

    std::cout << "Enter the expression: ";
    std::string expression{};
    std::getline(std::cin, expression);
    std::cout << purgeWhiteSpaces(expression);

    return 0;
}