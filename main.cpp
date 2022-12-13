#include "inputdebug.hpp"

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