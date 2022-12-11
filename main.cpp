#include "input.hpp"
#include <algorithm> //for std::remove_if

std::string purgeWhiteSpaces(const std::string& str)
{
    std::string str_copy{str};
    str_copy.erase(std::remove_if(str_copy.begin(), str_copy.end(), isspace), str_copy.end());
    return str_copy;
}


int main()
{

    std::cout << "Enter the expression: ";
    std::string expression{};
    std::getline(std::cin, expression);
    std::cout << purgeWhiteSpaces(expression);

    return 0;
}