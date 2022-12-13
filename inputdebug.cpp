#include "inputdebug.hpp"

void purgeRepeatingPluses(std::string &str)
{
    for (int i{0}; i < str.size(); ++i)
    {
        int j{i};
        if (str[i] == '+' && str[i + 1] == '+')
        {
            while (str[j] == '+')
            {
                ++j;
            }
            str.erase(i, j);
            str.insert(i, "+");
        }
    }
}

Brackets areBracketsEven(const std::string &str)
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

Brackets areBracketsEncapsulated(const std::string &str)
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

void cancelRowOfSigns(std::string &str)
{
    // firstly lets check if there is anything to cancel at all
    if (str.size() <= 1)
    {
        return;
    }
}


//reserved for a further review, probably going to delete anyway
//shit isn't understandable at all
/* void cancelOutSigns(std::string &str)
{
    int i{0};

    for (i = 0; i < str.size(); ++i)
    {
        int minus_signs{0};
        if (str[i] == '-' || str[i] == '+')
        {
            x1x2scope signs_position = {0, 0};

            int j{};
            for (j = i; (str[j] == '+' || str[j] == '-' || str[j] == '('); ++j)
            {
                if (str[j] == '-')
                {
                    ++minus_signs;
                }
                signs_position = {i, j + 1};
            }
            if (minus_signs % 2 == 0)
            {
                str.erase(signs_position[0], signs_position[1]);
                str.insert(signs_position[0], "+");
            }
            else
            {
                str.erase(signs_position[0], signs_position[1]);
                str.insert(signs_position[0], "-");
            }
        }
    }
    std::cout << str << '\n';
} */