#include<iostream>
using namespace std;
// 时间复杂度线性正比递归深度
void reverse(int *, int, int)
{
}
void reverse (int * A, int n)
{
    reverse(A, 0, n - 1);
}
void reserse(int* A, int lo, int hi)
{
    if (lo < hi)
    {
        swap(A[lo], A[hi]);
        reverse (A, lo + 1, hi - 1);
    }
}
int main()
{
    return 0;
}