#include <iostream>
int Func(int n)
{
    if (n == 0)
    {
        return 1;
    }
    
    return Func(n - 1) << 1;
}
int main()
{
    std:: cout << Func(5) << std:: endl;
    return 0;
}