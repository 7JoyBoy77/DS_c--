#ifndef _OPERATOR_
#define _OPERATOR_
#include <iostream>
using namespace std;

#define total 9
typedef enum 
{
    Add,
    Sub,
    Mul,
    Div,
    Pow,
    Fac,
    L_p,
    R_p,
    EOE
} Operator;
// "+", "-", "*", "/", "^", "!", "(", ")", "\0",
const char pri[total][total] = //[栈顶][当前]
    {
        '>', '>', '<', '<', '<', '<', '<', '>', '>', //  '+'
        '>', '>', '<', '<', '<', '<', '<', '>', '>', //  '-'
        '>', '>', '>', '>', '<', '<', '<', '>', '>', //  '*'
        '>', '>', '>', '>', '<', '<', '<', '>', '>', //  '/'
        '>', '>', '>', '>', '>', '<', '<', '>', '>', //  '^'
        '>', '>', '>', '>', '>', '>', ' ', '>', '>', //  '!'
        '<', '<', '<', '<', '<', '<', '<', '=', ' ', //  '('
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', //  ')'
        '<', '<', '<', '<', '<', '<', '<', ' ', '=', //  '\0'
     //   +    -    *    /    ^   !    (    )    \0
};

Operator optr_judge(const char op)
{
    switch (op)
    {
    case '+':
        return Add;
    case '-':
        return Sub;
    case '*':
        return Mul;
    case '^':
        return Div;
    case '!':
        return Fac;
    case '(':
        return L_p;
    case ')':
        return R_p;
    case '\0':
        return EOE;
    default:
        exit(-1);
    }
}

char Compare_priority(int stack_optr, int current_optr)
{
    return pri[stack_optr][current_optr];
}


#endif