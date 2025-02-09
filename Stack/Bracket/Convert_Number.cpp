#include<iostream>
#include<Stack.h>
using namespace std;

// 进制转换
void Convert(Stack<char> &s, int n, int base)
{
    const char arr[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    if (n > 0)
    {
        Convert(s, n / base, base);
        s.push(arr[n % base]);
    }
    
}
void Convert_iteration(Stack<char> &s, int n, int base)
{
    const char arr[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while (n > 0)
    {
        s.push(arr[n % base]);
        n /= base;
    }

    
}
int main()
{
    return 0;
}