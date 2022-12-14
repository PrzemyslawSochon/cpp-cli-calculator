#include "inputdebug.hpp"
#include "settings.hpp"
#include <cctype>

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
        std::cout << "Would you like calculate another expression? (y/n) ";
        char first{consoleInputCritErrHandling()[0]};
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

void simplifyRepeatingSigns(std::string &str)
{
    for (int i{0}; i < str.size() - 1; ++i)
    {
        if (str[i] == '-' && str[i + 1] == '-')
        {
            str.erase(i, 2);
            str.insert(i, "+");
            --i;
        }
        else if (str[i] == '-' && str[i + 1] == '+')
        {
            str.erase(i, 2);
            str.insert(i, "-");
            --i;
        }
        else if (str[i] == '+' && str[i + 1] == '+')
        {
            str.erase(i, 1);
            --i;
        }
        else if (str[i] == '+' && str[i + 1] == '-')
        {
            str.erase(i, 2);
            str.insert(i, "-");
            --i;
        }
    }
}

void handleDoubleAsterisks(std::string &str)
{
    for (int i{0}; i < str.size() - 1; ++i)
    {
        if (str[i] == '*' && str[i + 1] == '*')
        {
            if (g_treat_double_asterisks_as_exponent)
            {
                str.erase(i, 2);
                str.insert(i, "^");
                --i;
            }
            else
            {
                std::cerr << "Error, double asterisks!\n";
                return;
            }
        }
    }
}

void handleCommas(std::string &str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] == ',')
        {
            if (g_treat_comma_as_decimal_fraction)
            {
                str.erase(i, 1);
                str.insert(i, ".");
            }
            else
            {
                std::cerr << "Error, comma!\n";
                return;
            }
        }
    }
}

void handleBrackets(std::string &str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] == '[' || str[i] == '{')
        {
            if (g_treat_all_brackets_as_parenthesis)
            {
                str.erase(i, 1);
                str.insert(i, "(");
            }
            else
            {
                std::cerr << "error, forbidden brackets\n";
                return;
            }
        }
        else if (str[i] == ']' || str[i] == '}')
        {
            if (g_treat_all_brackets_as_parenthesis)
            {
                str.erase(i, 1);
                str.insert(i, ")");
            }
            else
            {
                std::cerr << "error, forbidden brackets\n";
                return;
            }
        }
        /* switch (str[i])
        {
        case '[':
        case '{':
            if (g_treat_all_brackets_as_parenthesis)
            {
                str.erase(i, 1);
                str.insert(i, "(");
            }
            else
            {
                std::cerr << "error, forbidden brackets\n";
                return;
            }
        case ']':
        case '}':
            if (g_treat_all_brackets_as_parenthesis)
            {
                str.erase(i, 1);
                str.insert(i, ")");
            }
            else
            {
                std::cerr << "error, forbidden brackets\n";
                return;
            }
        } */
    }
}

void handleBackwardSlash(std::string &str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] == '\\')
        {
            if (g_treat_backward_slash_as_division)
            {
                str.erase(i, 1);
                str.insert(i, "/");
            }
            else
            {
                std::cerr << "Error, backward slash!\n";
                return;
            }
        }
    }
}

void handleModulo(std::string &str)
{

    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] == '%')
        {
            if (!g_xor_percentage)
            {
                std::cerr << "Error, percentage!\n";
                return;
            }
            else if (g_treat_percentage_as_decimal)
            {
                str.erase(i, 1);
                str.insert(i, "/100");
            }
        }
    }
}

void handleExclamation(std::string &str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] == '!')
        {
            if (!g_treat_exclamation_as_factorial)
            {
                std::cerr << "Error, exclamation!\n";
                return;
            }
        }
    }
}

void handleBracketsAdjacentSymbols(std::string &str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] == '(' && isalnum(str[i - 1]) && i > 0)
        {
            if (g_treat_parenthesis_adjacent_symbols_as_multiplication)
            {
                str.insert(i - 1, "*");
            }
            else
            {
                std::cerr << "Error, adjacent number to bracket!\n";
                return;
            }
        }
        else if (str[i] == ')' && isalnum(str[i + 1]) && i < str.size() - 1)
        {
            if (g_treat_parenthesis_adjacent_symbols_as_multiplication)
            {
                str.insert(i, "*");
            }
            else
            {
                std::cerr << "Error, adjacent number to bracket!\n";
                return;
            }
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
                // if char position reached -1 (out of scope) interrupt the loop
                if (j <= -1)
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
        // if found opening bracket, look for its closing counterpart
        else if (str[i] == '(')
        {
            for (int j{i + 1}; j <= str.size(); ++j)
            {
                // if char position exceeded str size (out of scope) interrupt the loop
                if (j >= str.size())
                {
                    std::cout << "Brackets aren't correctly encapsulated. "
                              << "See opening bracket `(` at position " << i << ".\n";
                    return Brackets::err_opening_absence;
                }

                if (str[j] == ')')
                {
                    break;
                }
            }
        }
    }
    return Brackets::ok;
}

void handleNonAsciiChars(std::string &str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] > 127)
        {
            if (g_trim_non_ascii_chars)
            {
                str.erase(i, 1);
                --i;
            }
            else
            {
                std::cerr << "Non-ASCII character at position " << i << " isn't supported.\n";
                return;
            }
        }
    }
}
