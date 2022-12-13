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

        trimRepeatingPluses(expression);
        std::cout << "Mathematical expression after trimming pluses is:\n";
        printMathExpression(expression);

        areBracketsPaired(expression);
        areBracketsEncapsulated(expression);
    } while (askForConfirmation());

    return 0;
}