#include "stream_dbg.hpp"
#include <limits>
#include <iostream>

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

std::string removeTrailingZeros(const double &value)
{
    std::string str = std::to_string(value);
    std::size_t decimal_pos = str.find('.');
    std::size_t last_nonzero = str.find_last_not_of('0');
    // If all characters after the decimal point are zeros
    if (last_nonzero == decimal_pos)
    {
        // Remove the decimal point as well
        last_nonzero--;
    }
    // Erase all characters after the last non-zero character
    str.erase(last_nonzero + 1);

    return str;
}