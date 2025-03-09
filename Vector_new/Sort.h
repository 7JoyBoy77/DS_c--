#include <iostream>
#include <utility>
template <typename T>
void BubbleSort(T *A, int lo, int hi)
{
    for (int i = lo; i < hi - 1; i++)
    {
        // ¿ØÖÆ±êÖ¾
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
