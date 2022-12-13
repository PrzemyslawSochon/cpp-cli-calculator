#include <cassert>

double expression(double a, double b, char symbol)
{
    switch (symbol)
    {
        case '+': {return a+b;}
        case '-': {return a-b;}
        case '/': {return a/b;}
        case '*': {return a*b;}
        default: {assert(symbol && "Operator not found!");}
    }
}