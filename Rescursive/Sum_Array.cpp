#include<iostream>
using namespace std;
int Func(int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
// 递归问题分解为两个问题，一个问题可以独立求解，另一个就是剩余部分与第一个问题结构雷同。
// first_problem:A[n-1], the other_problem:sum(A, n-1);
int Func_rescursive(int arr[], int n)
{
    if (n > 0)
    {
    return arr[n - 1] + Func_rescursive(arr, n - 1);
    }
    else
    {
        return 0;
    }    
}
int Binary_rescursive(int arr[], int lo, int hi)
{
    int mi = 0;
    if(lo == hi)
    {
        return arr[lo];
    }
    // 一般lo < hi
    else
    {
        mi = (lo + hi) >> 1; 
        // 二分递归 mi + 1的原理
        return Binary_rescursive(arr, lo, mi) + Binary_rescursive(arr , mi + 1, hi);
    }
}
int Func_iteration(int arr[], int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += arr[n - 1];
        n--;
        // return arr[n - 1];
    }
    return sum;
}        
int main()
{
    int arr[5] = {1, 28,291,42,2};
    cout << Func(arr,5) << endl;
    cout << Func_rescursive(arr,5) << endl;
    cout << Func_iteration(arr,5) << endl;
    cout << Binary_rescursive(arr, 0, 4) << endl;
    return 0;
}