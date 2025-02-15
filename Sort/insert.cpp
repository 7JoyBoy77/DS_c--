#include <iostream>
#include <array>
#include <random>
// 插入排序是一种最简单直观的排序算法，它的工作原理是通过构建有序序列，
// 对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
int main()
{
    // 以随机值播种，若可能
    std::random_device r;
    // 选择 1 与 6 间的随机数
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    std::array<int, 10> arr;
    for (int i = 0; i < 10; i++)
    {
        arr[i] = uniform_dist(e1);
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while ((j >= 0) && (key < arr[j]))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (auto &i : arr)
    {
        std::cout << i << " ";
    }
    return 0;
}