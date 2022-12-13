#include "inputdebug.hpp"

int main()
{
    do
    {
        std::cout << "Enter a mathematical expression: ";
        std::string expression{};

        expression = consoleInputCritErrHandling();
        std::cout << "Mathematical expression after checking for critical errors is:\n";
        printMathExpression(expression);

        purgeWhiteSpaces(expression);
        std::cout << "Mathematical expression after removing whitespaces is:\n";
        printMathExpression(expression);

        simplifyRepeatingMinuses(expression);
        std::cout << "Mathematical expression after simplifying minuses is:\n";
        printMathExpression(expression);

        areBracketsPaired(expression);
        areBracketsEncapsulated(expression);
    } while (confirm());

    return 0;
}