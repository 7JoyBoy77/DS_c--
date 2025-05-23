#include <iostream>
#include <vector>
// 二分查找严格有序
using Rank = int;
template <typename T>
Rank binarySearch(std::vector<T> vec, Rank begin, Rank end, const T &value)
{
    if (begin > end)
    {
        return -1;
    }
    Rank i = begin + (end - begin) / 2;
    if (value == vec[i])
    {
        return i;
    }
    else if (value < vec[i])
    {
        binarySearch(vec, begin, i - 1, value);
    }
    else
    {
        binarySearch(vec, i + 1, end, value);
    }
}

template <typename T>
Rank binarySearch(std::vector<T> vec, T &value)
{
    binarySearch(vec, 0, vec.size() - 1, value);
}