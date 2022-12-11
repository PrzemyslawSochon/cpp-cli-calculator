#include "input.hpp"
#include <algorithm> //for std::remove_if

enum class bracketFlags
{
    ok,
    error,

    size
};

std::string purgeWhiteSpaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
    return str;
}

bracketFlags areBracketsCorrect(const std::string& str)
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
                    return bracketFlags::error;
                }
            }
        }
    }
}


int main()
{

    std::cout << "Enter the expression: ";
    std::string expression{};
    std::getline(std::cin, expression);
    std::cout << purgeWhiteSpaces(expression);

    return 0;
}