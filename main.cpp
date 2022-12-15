#include "expression_dbg.hpp"
#include "solution.hpp"
#include "stream_dbg.hpp"
#include <exception>

int main()
{
    do
    {
        std::cout << "Enter a mathematical expression\n";
        std::string expression{};

        try
        {
            expression = consoleInputDebug();
            printMathExpression(expression);

            trimWhiteSpaces(expression);
            printMathExpression(expression);

            std::cout << debugRepeatingSigns(expression);
            printMathExpression(expression);

            std::cout << debugDoubleAsterisks(expression);
            printMathExpression(expression);

            std::cout << debugCommas(expression);
            printMathExpression(expression);

            std::cout << debugBrackets(expression);
            printMathExpression(expression);

            std::cout << debugBackSlash(expression);
            printMathExpression(expression);

            std::cout << debugPercentSign(expression);
            printMathExpression(expression);

            std::cout << debugExclamation(expression);
            printMathExpression(expression);

            std::cout << debugLiterals(expression);
            printMathExpression(expression);

/*             debugBracketAdjacentSymbols(expression);
            std::cout << "After handling bracket adjacent symbols\n";
            printMathExpression(expression); */

            areBracketsPaired(expression);
            areBracketsEncapsulated(expression);
        }
        catch (const char *exception)
        {
            std::cerr << "Error: " << exception << '\n';
            continue;
        }

    } while (again());

    return 0;
}