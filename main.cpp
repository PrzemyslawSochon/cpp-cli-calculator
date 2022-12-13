#include "input.hpp"
#include <algorithm> //for std::remove_if
#include <array>
#include <vector>

int main()
{
    std::cout << "Enter the expression: ";
    std::string expression{};
    std::getline(std::cin, expression);

    purgeWhiteSpaces(expression);
    std::cout << expression << '\n';

    areBracketsEven(expression);
    areBracketsEncapsulated(expression);
    
    purgeRepeatingPluses(expression);
    std::cout << expression << '\n';

    return 0;
}