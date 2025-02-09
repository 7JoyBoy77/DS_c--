#ifndef _READ_STRING_
#define _READ_STRING_

#include "operator.h"
#include "calculator.h"
#include "Stack.h"
// 定义两个栈，一个操作符栈，一个操作数栈。
double read_string(char *str_optr)
{
    Stack<char> stack_optr;
    Stack<double> stack_number;
    int flag = 0;
    // 后缀先入'\0'
    stack_optr.push('\0');
    while (!stack_optr.Empty())
    {
        // ')'没有优先级问题，
        while (str_optr[flag] == ' ' || str_optr[flag] == '\t')
        {
            flag++;
        }

        if (str_optr[flag] >= '0' && str_optr[flag] <= '9')
        {
            stack_number.push(str_optr[flag]);
            flag++;
        }
        else
        {
            switch (str_optr[flag])
            {

            case '<': //栈顶运算符优先级小于当前运算符优先级
                stack_optr.push(str_optr[flag]);
                flag++;
                break;
            case '=':
                stack_optr.pop();
                flag++;
                break;
            case '>':
                if (str_optr[flag] != '!')
                {
                    double second_num = stack_number.pop();
                    double first_num = stack_number.pop();
                    stack_number.push(Calc(first_num, str_optr[flag], second_num));
                    flag++;
                    break;
                }
                else
                {
                    double only_num = stack_number.pop();
                    stack_number.push(Calc(only_num));
                    flag++;
                    break;
                }

            default:
                break;
            }
        }
    }
    return stack_number.pop();
}
#endif