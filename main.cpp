#include "inputdebug.hpp"
#include "solution.hpp"

int main()
{
    do
    {
        std::cout << "Enter a mathematical expression\n";
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

        handleDoubleAsterisks(expression);
        std::cout << "Expression after handling double Asterisks is\n";
        printMathExpression(expression);

        handleCommas(expression);
        std::cout << "After handling commas\n";
        printMathExpression(expression);

        handleBrackets(expression);
        std::cout << "After handling brackets\n";
        printMathExpression(expression);

        handleBackwardSlash(expression);
        std::cout << "After handling backward slashes\n";
        printMathExpression(expression);

        handleModulo(expression);
        std::cout << "After handling modulo\n";
        printMathExpression(expression);

        handleExclamation(expression);
        std::cout << "After handling exclamation\n";
        printMathExpression(expression);

        swapLiteralsWithConstants(expression);
        std::cout << "After swap\n";
        printMathExpression(expression);

        handleBracketsAdjacentSymbols(expression);
        std::cout << "After handling bracket adjacent symbols\n";
        printMathExpression(expression);

        areBracketsPaired(expression);
        areBracketsEncapsulated(expression);

        StringPosition str_pos{extractFromParenthesis(expression)};
        std::string sub_expression{str_pos.str};
        std::cout << "The extracted string is: " << sub_expression << '\n';

        Expression expr{turnStringIntoExpression(sub_expression)};
        std::cout << "Contents of the sub strings are:\n"
                  << "First value: " << expr.variable1 << '\n'
                  << "Operator: " << expr.symbol << '\n'
                  << "Second value: " << expr.variable2 << '\n';

        double result{calculateResultOfExpression(expr)};
        std::cout << sub_expression << '=' << result << '\n';

        insertResultToExpression(expression, result, str_pos.x1, str_pos.x2);
        std::cout << "Mathematical expression after solving one of expressions:\n";
        printMathExpression(expression);

    } while (confirm());

    return 0;
}