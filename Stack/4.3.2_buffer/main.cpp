#include"calculator.h"
#include"operator.h"
#include"read_string.h"
#include<cstring>
int main()
{
    char* str =(char *) "(0! + 1)*2^(3! + 4) - (5! -67 - (8 + 9))";
    cout << read_string(str) << endl;
}