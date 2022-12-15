#include "stream_dbg.hpp"

std::string consoleInputDebug()
{
    constexpr std::streamsize max_chars{std::numeric_limits<std::streamsize>::max()};

    do
    {
        std::string console_input{};
        if (std::getline(std::cin, console_input).fail())
        {
            std::cin.clear();
            std::cin.ignore(max_chars, '\n');
            std::cerr << "An error occurred while reading from the console.\n"
                      << "Please try again.\n";
            std::cerr.flush();
            continue;
        }
        if (console_input.empty())
        {
            std::cin.clear();
            std::cin.ignore(max_chars, '\n');
            std::cerr << "The input string is empty. Please try again.\n";
            std::cerr.flush();
            continue;
        }

        return console_input;
    } while (true);
}

bool confirm()
{
    do
    {
        std::cout << "(y/n)\n";
        char first{consoleInputDebug()[0]};
        switch (first)
        {
        case 'y':
        case 'Y':
            return true;
        case 'n':
        case 'N':
            return false;
        }
    } while (true);
}

bool again()
{
    do
    {
        std::cout << "Do you wanna try again? ";
        return (confirm());
    } while (true);
}