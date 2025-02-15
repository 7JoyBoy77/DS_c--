#include <iostream>
#include <array>
#include <random>
// 选择排序首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
// 再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
// 重复第二步，直到所有元素均排序完毕。
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
    for(int i = 0; i < arr.size() - 1; i++)
    {
        int min_index = i;
        for(int j = i + 1; j < arr.size(); j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
    for (auto &i : arr)
    {
        std::cout << i << " ";
    }

    return 0;
}