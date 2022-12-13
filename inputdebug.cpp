#include "inputdebug.hpp"

std::string consoleInputCritErrHandling()
{
    constexpr std::streamsize max_chars{std::numeric_limits<std::streamsize>::max()};

    do
    {
        std::string console_input{};
        if (std::getline(std::cin, console_input).fail())
        {
            std::cin.clear();
            std::cin.ignore(max_chars, '\n');
            std::cerr << "An error occurred while reading from the console.\n";
            std::cerr << "Please try again.\n";
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

void trimRepeatingPluses(std::string &str)
{
    for (int i{0}; i < str.size() - 1; ++i)
    {
        if (str[i] == '+' && str[i + 1] == '+')
        {
            str.erase(i, 1);
            --i;
        }
    }
}

Brackets areBracketsPaired(std::string_view str)
{
    int open_brackets{0};
    int close_brackets{0};

    for (const char &i : str)
    {
        if (i == '(')
            ++open_brackets;
        else if (i == ')')
            ++close_brackets;
    }

    if (open_brackets == close_brackets)
    {
        return Brackets::ok;
    }
    else
    {
        std::cout << "Brackets aren't paired.\n";
        return Brackets::err_odd_number;
    }
}

Brackets areBracketsEncapsulated(std::string_view str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        // if found closing bracket, look for its opening counterpart
        if (str[i] == ')')
        {
            for (int j{i - 1}; j >= -1; --j)
            {
                // char position reached -1 (out of scope) = couldn't find open bracket
                if (j == -1)
                {
                    std::cout << "Brackets aren't correctly encapsulated. "
                              << "See closed bracket `)` at position " << i << ".\n";
                    return Brackets::err_opening_absence;
                }

                if (str[j] == '(')
                {
                    break;
                }
            }
        }
    }
    return Brackets::ok;
}