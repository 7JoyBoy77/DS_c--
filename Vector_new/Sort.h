#pragma once
#include <iostream>
#include <utility>
template <typename T>
void BubbleSort(T *A, int lo, int hi)
{
    for (int i = lo; i < hi - 1; i++)
    {
        bool disorder_flag = false;
        for (int j = lo; (j < hi - 1 - (i - lo)); j++)
        {
            if (A[j] > A[j + 1])
            {
                std::swap(A[j], A[j + 1]);
                disorder_flag = true;
            }
        }
        if (!disorder_flag)
        {
            break;
        }
    }
}

template <typename T>
int BinaryFind(T *A, const T &val, int lo, int hi)
{
    if (val < A[lo] || val > A[hi])
    {
        return -1;
    }
    // int mid = (lo + hi) / 2;
    int mid = lo + (hi - lo) / 2;
    if (A[mid] < val)
    {
        return BinaryFind(A, val, mid + 1, hi);
    }
    else if (A[mid] > val)
    {
        return BinaryFind(A, val, lo, mid - 1);
    }
    else
    {
        return mid;
    }
}
