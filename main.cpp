#include "inputdebug.hpp"
#include <algorithm> //for std::remove_if
#include <array>
#include <vector>

int main()
{
    std::cout << "Enter the expression: ";
    std::string expression{};
    expression = consoleInputCritErrHandling();

    purgeWhiteSpaces(expression);
    std::cout << expression << '\n';

    areBracketsPaired(expression);
    areBracketsEncapsulated(expression);

    trimRepeatingPluses(expression);
    std::cout << expression << '\n';

    return 0;
}