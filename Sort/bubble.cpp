#include <iostream>
#include <array>
#include <random>
// 冒泡排序，冒泡排序（Bubble Sort）也是一种简单直观的排序算法。
// 它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。
// 这个算法的名字由来是因为越小的元素会经由交换慢慢"浮"到数列的顶端。
int main()
{
    // 以随机值播种，若可能
    std::random_device r;
    // 选择 1 与 6 间的随机数
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10);
    std::array<int , 10 > arr;
    for (int i = 0; i < 10; i++)
    {
        arr[i] = uniform_dist(e1);
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < (10 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (auto &i : arr)
    {
        std::cout << i << " ";
    }
    
    return 0;
}