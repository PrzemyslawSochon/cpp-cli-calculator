#include "input.hpp"
#include <algorithm> //for std::remove_if

enum class brackets
{
    ok,

    err_odd_number,
    err_opening_absence,

    size
};

std::string purgeWhiteSpaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
    return str;
}

brackets areBracketsEven(const std::string& str)
{
    int open_bracket_counter{0};
    int close_bracket_counter{0};

    for(const char& i : str)
    {
        if(i=='(') ++open_bracket_counter;
        else if (i==')') ++close_bracket_counter;
    }

    if(open_bracket_counter==close_bracket_counter)
    {
        return brackets::ok;
    }
    else {return brackets::err_odd_number;}
}


brackets areBracketsEncapsulated(const std::string& str)
{
    for(int i{0};i<str.size();++i)
    {
        //if found closing bracket, look for its opening counterpart
        if(str[i]==')')
        {
            static int last_position_mark{i};
            for (int j{last_position_mark-1};j>=0;--j)
            {
                if(str[j]=='(')
                {
                    last_position_mark=j;
                    break;
                }

                if(j==0)
                {
                    return brackets::err_opening_absence;
                }
            }
        }
    }
    return brackets::ok;
}


int main()
{

    std::cout << "Enter the expression: ";
    std::string expression{};
    std::getline(std::cin, expression);
    std::cout << purgeWhiteSpaces(expression) << '\n';

    if(areBracketsEncapsulated(expression)==brackets::ok && areBracketsEven(expression)==brackets::ok)
    {
        std::cout << "OK!\n";
    }
    else
    {
        std::cout << "NOT OK!\n";
    }
    return 0;
}