#include "expression_dbg.hpp"
#include "stream_dbg.hpp"
#include "settings.hpp"
#include "solution.hpp"

int main()
{
    /* std::cout << std::fixed << std::setprecision(1); */
    do
    {
        std::cout << "Enter a mathematical expression.\n";
        std::string expression{};

        // consoleInputDebug is just std::cin with extra steps
        expression = consoleInputDebug();
        trimWhiteSpaces(expression);

        try
        {
            std::cout << debugNonAsciiChars(expression);
            std::cout << areBracketsPaired(expression);
            std::cout << areBracketsEncapsulated(expression);
            std::cout << debugOuterOperators(expression);

            std::cout << debugPercentSign(expression);
            printMathExpression(expression);

            std::cout << debugClutchedOperators(expression);


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

            std::cout << debugExclamation(expression);
            printMathExpression(expression);

            std::cout << debugLiterals(expression);
            printMathExpression(expression);

            std::cout << debugBracketAdjacentSymbols(expression);
            printMathExpression(expression);
        }
        catch (const char *exception)
        {
            std::cerr << "Error: " << exception << '\n';
            std::cerr.flush();
            continue;
        }

                solveMostSignificantOperator(expression);
                printMathExpression(expression);

    } while (again());

    return 0;
}