#include "expression_dbg.hpp"
#include "solution.hpp"
#include "stream_dbg.hpp"

int main()
{
    do
    {
        std::cout << "Enter a mathematical expression\n";
        std::string expression{};

        expression = consoleInputDebug();
        std::cout << "Mathematical expression after checking for critical errors is:\n";
        printMathExpression(expression);

        trimWhiteSpaces(expression);
        std::cout << "Mathematical expression after removing whitespaces is:\n";
        printMathExpression(expression);

        debugRepeatingSigns(expression);
        std::cout << "Mathematical expression after simplifying signs is:\n";
        printMathExpression(expression);

        debugDoubleAsterisks(expression);
        std::cout << "Expression after handling double Asterisks is\n";
        printMathExpression(expression);

        debugCommas(expression);
        std::cout << "After handling commas\n";
        printMathExpression(expression);

        debugBrackets(expression);
        std::cout << "After handling brackets\n";
        printMathExpression(expression);

        debugBackSlash(expression);
        std::cout << "After handling backward slashes\n";
        printMathExpression(expression);

        debugPercentSign(expression);
        std::cout << "After handling modulo\n";
        printMathExpression(expression);

        debugExclamation(expression);
        std::cout << "After handling exclamation\n";
        printMathExpression(expression);

        debugLiterals(expression);
        std::cout << "After swap\n";
        printMathExpression(expression);

        debugBracketAdjacentSymbols(expression);
        std::cout << "After handling bracket adjacent symbols\n";
        printMathExpression(expression);

        areBracketsPaired(expression);
        areBracketsEncapsulated(expression);

        std::cout << results(parenthesis(expression));

    } while (confirm());

    return 0;
}