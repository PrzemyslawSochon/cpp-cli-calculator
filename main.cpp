#include "input.hpp"
#include <algorithm> //for std::remove_if
#include <array>
#include <string>
#include <vector>

//x_scope can hold vector of coordinates such as [[1,2],[3,4],[10,12]]
using x_scope = std::array<int,2>;

inline void purgeWhiteSpaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

Brackets areBracketsEven(const std::string& str)
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
        return Brackets::ok;
    }
    else
    {
        std::cout << "Brackets aren't paired.\n";
        return Brackets::err_odd_number;
    }
}

Brackets areBracketsEncapsulated(const std::string& str)
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
                    return Brackets::err_opening_absence;
                }

                if(str[j]=='(')
                {
                    break;
                }
            }
        }
    }
    return Brackets::ok;
}

void cancelRowOfSigns(std::string& str)
{
    //firstly lets check if there is anything to cancel at all
    if(str.size()<=1) {return;}

}

void cancelOutSigns(std::string& str)
{
    int i{0};

    for(i=0;i<str.size();++i)
    {
        int minus_signs{0};
        if(str[i]=='-' || str[i]=='+')
        {
            x_scope signs_position = {0,0};

            int j{};
            for(j=i; (str[j]=='+' || str[j]=='-' || str[j]=='(') ;++j)
            {
                if(str[j]=='-'){++minus_signs;}
                signs_position = {i,j+1};
            }
            if(minus_signs%2==0)
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
}

//order of performing math operations


int main()
{
    std::cout << "Enter the expression: ";
    std::string expression{};
    std::getline(std::cin, expression);

    purgeWhiteSpaces(expression);
    std::cout << expression << '\n';

    areBracketsEven(expression);
    areBracketsEncapsulated(expression);
    cancelOutSigns(expression);

    return 0;
}