#include "input.hpp"
#include <algorithm> //for std::remove_if
#include <array>
#include <vector>

//x_scope can hold vector of coordinates such as [[1,2],[3,4],[10,12]]
using x_scope = std::vector<std::array<int,2>>;

enum class brackets
{
    ok,

    err_odd_number,
    err_opening_absence,

    size
};

inline void purgeWhiteSpaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
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
    else
    {
        std::cout << "Brackets aren't paired.\n";
        return brackets::err_odd_number;
    }
}


brackets areBracketsEncapsulated(const std::string& str)
{
    for(int i{0};i<str.size();++i)
    {
        //if found closing bracket, look for its opening counterpart
        if(str[i]==')')
        {
            for (int j{i-1};j>=-1;--j)
            {
                if(j==-1)
                {
                    std::cout << "Brackets aren't correctly encapsulated. "
                              << "See closed bracket `)` at position " << i << ".\n";
                    return brackets::err_opening_absence;
                }

                if(str[j]=='(')
                {
                    break;
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
    purgeWhiteSpaces(expression);
    std::cout << expression << '\n';

    return 0;
}