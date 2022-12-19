#include "expression_dbg.hpp"
#include "settings.hpp"

std::string_view debugNonAsciiChars(std::string &str)
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
                throw "Encountered non-ASCII character, you can auto erase them in settings.";
            }
        }
    }
    if (g_verbose)
    {
        return "Debugged non-ASCII characters.\n";
    }
    else
    {
        return "";
    }
}


std::string_view debugBracketAdjacentSymbols(std::string &str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] == '(' && i > 0 && isAlphanumeric(str[i - 1]))
        {
            if (g_treat_parenthesis_adjacent_symbols_as_multiplication)
            {
                str.insert(i, "*");
                ++i;
            }
            else
            {
                throw "Omitting asterisks between variables and parenthesis is turned off in settings.";
            }
        }
        else if (str[i] == ')' && i < str.size() - 1 && isAlphanumeric(str[i + 1]))
        {
            if (g_treat_parenthesis_adjacent_symbols_as_multiplication)
            {
                str.insert(i + 1, "*");
                ++i;
            }
            else
            {
                throw "Omitting asterisks between variables and parenthesis is turned off in settings.";
            }
        }
    }
    if (g_verbose)
    {
        return "Debugged adjacent symbols to parenthesis.\n";
    }
    else
    {
        return "";
    }
}

std::string_view areBracketsPaired(std::string_view str)
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
        if (g_verbose)
        {
            return "Number of opened and closed brackets matches.\n";
        }
        else
        {
            return "";
        }
    }
    else
    {
        throw "Number of opened and closed brackets doesn't match!";
    }
}

std::string_view areBracketsEncapsulated(std::string_view str)
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
                    throw "Brackets aren't correctly encapsulated!";
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
                    throw "Brackets aren't correctly encapsulated!";
                }

                if (str[j] == ')')
                {
                    break;
                }
            }
        }
    }
    if (g_verbose)
    {
        return "Brackets are encapsulated.\n";
    }
    else
    {
        return "";
    }
}

std::string_view debugOuterOperators(std::string &str)
{
    if (isEFRMD(str[0]))
    {
        throw "Illegal operator at the beginning of the expression!";
    }
    if (isERMDAS(str.back()))
    {
        throw "Illegal operator at the end of the expression!";
    }
    for (int i{0}; i < str.size() - 1; ++i)
    {
        if ((str[i] == ')' && isERMDAS(str[i - 1])) || str[i] == '(' && isEFRMD(str[i + 1]))
        {
            throw "Illegal operator next to parenthesis!";
        }
    }
    if (g_verbose)
        return "Debugged adjacent operators\n";
    else
    {
        return "";
    }
}

std::string_view debugPercentSign(std::string &str)
{

    for (int i{0}; i < str.size()-1; ++i)
    {
        if (str[i] == '%')
        {
            if (!g_xor_percentage)
            {
                throw "Percent signs `%` are turned off in settings.";
            }
            else if (g_treat_percentage_as_decimal)
            {
                if((str[i]==str.back()||isAnyOperator(str[i+1])))
                {
                str.erase(i, 1);
                str.insert(i, "/100");
                i = i + 3;
                }
                else
                {
                    throw "No operation after percentage sign, can't swap for /100.";
                }
            }
        }
    }
    if (g_verbose)
    {
        return "Swapped all occurrences of percent signs `%` to division `/100`.\n";
    }
    else
    {
        return "";
    }
}

std::string_view debugClutchedOperators(std::string &str)
{
    for (int i{0}; i < str.size() - 1; ++i)
    {
        if (str[i] == '^' && str[i + 1] == '^')
        {
            throw "Clutched operator!";
        }
        else if (str[i] == '^' && str[i + 1] == '%')
        {
            throw "Clutched operator!";
        }
        else if (str[i] == '^' && str[i + 1] == '/')
        {
            throw "Clutched operator!";
        }
        else if (str[i] == '%' && str[i + 1] == '%')
        {
            throw "Clutched operator!";
        }
        else if (str[i] == '%' && str[i + 1] == '^')
        {
            throw "Clutched operator!";
        }
        else if (str[i] == '%' && str[i + 1] == '/')
        {
            throw "Clutched operator!";
        }
        else if (str[i] == '/' && str[i + 1] == '/')
        {
            throw "Clutched operator!";
        }
        else if (str[i] == '/' && str[i + 1] == '^')
        {
            throw "Clutched operator!";
        }
        else if (str[i] == '^' && str[i + 1] == '%')
        {
            throw "Clutched operator!";
        }
    }
    if (g_verbose)
        return "Debugged clutched operators\n";
    else
    {
        return "";
    }
}

std::string_view debugRepeatingSigns(std::string &str)
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
        else if ((str[i] == '(' && str[i + 1] == '+') ||
                 (str[i] == '^' && str[i + 1] == '+') ||
                 (str[i] == '%' && str[i + 1] == '+') ||
                 (str[i] == '*' && str[i + 1] == '+') ||
                 (str[i] == '/' && str[i + 1] == '+'))
        {
            str.erase(i + 1, 1);
        }
    }

    // clean leftover plus if present
    if (str[0] == '+')
    {
        str.erase(0, 1);
    }

    if (g_verbose)
    {
        return "Simplified signed values.\n";
    }
    else
    {
        return "";
    }
}

std::string_view debugDoubleAsterisks(std::string &str)
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
                throw "Double asterisks `**` are turned off in settings.";
            }
        }
    }
    if (g_verbose)
    {
        return "Swapped all occurrences of double asterisks `**` to caret signs `^`.\n";
    }
    else
    {
        return "";
    }
}

std::string_view debugCommas(std::string &str)
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
                throw "Commas `,` are turned off in settings.";
            }
        }
    }
    if (g_verbose)
    {
        return "Swapped all occurrences of commas `,` to dots `.`\n";
    }
    else
    {
        return "";
    }
}

std::string_view debugBrackets(std::string &str)
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
                throw "Any brackets other than parenthesis `()` are turned off in settings.";
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
                throw "Any brackets other than parenthesis `()` are turned off in settings.";
            }
        }
    }
    if (g_verbose)
    {
        return "Swapped all occurrences of bracket `[]` `{}` to parenthesis `()`\n";
    }
    else
    {
        return "";
    }
}

std::string_view debugBackSlash(std::string &str)
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
                throw "Backward slashes `\\` are turned off in settings.";
            }
        }
    }
    if (g_verbose)
    {
        return "Swapped all occurrences of backward slashes `\\` to forward slashes `/`.\n";
    }
    else
    {
        return "";
    }
}

std::string_view debugExclamation(std::string &str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        if (str[i] == '!')
        {
            if (!g_treat_exclamation_as_factorial)
            {
                throw "Exclamation marks `!` are disabled in settings.";
            }
        }
    }
    if (g_verbose)
    {
        return "Debugged exclamation `!` mark.\n";
    }
    else
    {
        return "";
    }
}

std::string_view debugLiterals(std::string &str)
{
    for (int i{0}; i < str.size() - 1; ++i)
    {
        if (str[i] == 'p' && str[i + 1] == 'i' && g_treat_pi_as_constant)
        {
            str.erase(i, 2);
            str.insert(i, mathConstants::pi_str);
            i = i + 5;
        }
        else if (str[i] == 'e' && g_treat_e_as_constant)
        {
            str.erase(i, 1);
            str.insert(i, mathConstants::e_str);
            i = i + 6;
        }
    }
    if (g_verbose)
    {
        if (g_treat_pi_as_constant && g_treat_e_as_constant)
        {
            return "Swapped `pi` and `e` literals to their respective constants.\n";
        }
        else if (g_treat_pi_as_constant)
        {
            return "Swapped `pi` literal to its constant.\n";
        }
        else if (g_treat_e_as_constant)
        {
            return "Swapped `e` literal to its constant.\n";
        }
    }
    else
    {
        return "";
    }
}