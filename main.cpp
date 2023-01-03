#include "expression_dbg.hpp"
#include "stream_dbg.hpp"
#include "settings.hpp"
#include "solution.hpp"

int main()
{
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
            std::cout << debugClutchedOperators(expression);
            std::cout << debugRepeatingSigns(expression);
            std::cout << debugDoubleAsterisks(expression);
            std::cout << debugCommas(expression);
            //std::cout << debugBrackets(expression);
            std::cout << debugBackSlash(expression);
            //std::cout << debugExclamation(expression);
            std::cout << debugLiterals(expression);
            //std::cout << debugBracketAdjacentSymbols(expression);
        }
        catch (const char *exception)
        {
            std::cerr << "Error: " << exception << '\n';
            std::cerr.flush();
            continue;
        }
                std::cout << "Expression after debugging:\n";
                printMathExpression(expression);
        
                solveMostSignificantOperator(expression);
                std::cout << "The final result is:\n";
                printMathExpression(expression);

    } while (again());

    return 0;
}
