#include "inputdebug.hpp"

int main()
{
    char key{13};
    do{
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

    std::cout << "Press Enter to input another expression. "
              << "Press anything else to exit.";
    
    std::cin >> key;
    }
    while (key==13);

    return 0;
}