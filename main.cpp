#include "inputdebug.hpp"
#include "solution.hpp"

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

        simplifyRepeatingSigns(expression);
        std::cout << "Mathematical expression after simplifying minuses is:\n";
        printMathExpression(expression);

        areBracketsPaired(expression);
        areBracketsEncapsulated(expression);

        std::string sub_expression{extractFromParenthesis(expression)};
        std::cout << "The extracted expression: " << sub_expression << '\n';

    } while (confirm());

    return 0;
}