// 计算函数
#ifndef _CALCULATOR_
#define _CALCULATOR_
#include<cmath>
double Calc(double first, char optr, double second)
{
    switch (optr)
    {
    case '+':
        return first + second;
        break;
    case '-':
        return first - second;
        break;
    case '*':
        return first * second;
        break;
    case '/':
        return first / second;
        break;
    case '^':
        return pow(first, second);
        break;

    default:
        exit(-1);
        // break;
    }
}
double Calc(double only)
{
    if (only == 1)
    {
        return 1;
    }
    return Calc(only - 1)*only;
    
}
#endif