#include <iostream>
#include <queue>
using namespace std;
#define CAPACITY 3
int test(int a)
{
   return a;
}
int main()
{
   int (*fp)(int a);
   fp = test;
   cout << fp(2) << endl;
   return 0;
}
