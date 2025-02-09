#include <iostream>
#include<Stack.h>
using namespace std;
bool Match_bracket(const char exp[], int lo, int hi)
{
    Stack<char> S;
    while (lo++ < hi)
    {
        
        switch (exp[lo])
        {
        case '{':
            S.push(exp[lo]);
            break;
        case '[':
            S.push(exp[lo]);
            break;
        case '(':
            S.push(exp[lo]);
            lo++;
            break;

        case '}':
        {
            if (S.top() != '{')
            {
                return false;
            }
            else
            {
                S.pop();
                break;
            }
        }
        case ']':
        {
            if (S.top() != '[')
            {
                return false;
            }
            else
            {
                S.pop();
                break;
            }
        }
        case ')':
        {
            if (S.top() != ')')
            {
                return false;
            }
            else
            {
                S.pop();
                break;
            }
        }

        default:
            break;
        }
    }
}
int main()
{
    return 0;
}