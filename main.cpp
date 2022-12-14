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
        std::cout << "Mathematical expression after simplifying signs is:\n";
        printMathExpression(expression);

        areBracketsPaired(expression);
        areBracketsEncapsulated(expression);

        std::string sub_expression{extractFromParenthesis(expression)};
        std::cout << "The extracted string: " << sub_expression << '\n';

        Expression expr{turnStringIntoExpression(sub_expression)};
        std::cout << "Contents of the sub strings are:\n"
                  << "First value: " << expr.variable1 << '\n'
                  << "Operator: " << expr.symbol << '\n'
                  << "Second value: " << expr.variable2 << '\n';

        std::cout << sub_expression << '=' << calculateResultOfExpression(expr) << '\n';

    } while (confirm());

    return 0;
}