#include "expression_dbg.hpp"
#include "solution.hpp"
#include "stream_dbg.hpp"
#include <exception>

int main()
{
    do
    {
        std::cout << "Enter a mathematical expression.\n";
        std::string expression{};

        expression = consoleInputDebug();
        trimWhiteSpaces(expression);

        try
        {
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

            std::cout << debugBracketAdjacentSymbols(expression);
            printMathExpression(expression);

            std::cout << areBracketsPaired(expression);
            std::cout << areBracketsEncapsulated(expression);
        }
        catch (const char *exception)
        {
            std::cerr << "Error: " << exception << '\n';
            std::cerr.flush();
            continue;
        }

    } while (again());

    return 0;
}