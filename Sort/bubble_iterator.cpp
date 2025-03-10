#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
void bubbleSort(std::vector<int> vec)
{
    /*
    std::vector<int>::iterator vec_end = vec.end();
    for (auto vec_i = vec.begin(); vec_i != vec_end; vec_i++)
    {
        for (auto vec_j = vec.begin(); vec_j != (vec_end - 1); vec_j++)
        {
            // swap 迭代器解引用类似解引用指针修改指向元素的值
            if ((*vec_j) > (*(vec_j + 1)))
            {
                std::swap(*vec_i, *vec_j);
            }
        }
    }
    for (auto &&i : vec)
    {
        std::cout << i << " ";
    }
    */
    auto end = vec.end();
    for (auto i = vec.begin(); i != end; ++i)
    {
        bool swapped = false;
        auto prev = vec.begin();
        auto current = prev;
        ++current;
        for (; current != (end - std::distance(vec.begin(), i)); ++prev, ++current)
        {
            if (*prev > *current)
            {
                std::swap(*prev, *current);
                swapped = true;
            }
        }
        // 如果某一轮没有发生交换，说明已经有序，可以提前结束排序
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    std::random_device r;
    // 选择 1 与 10 间的随机数
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, 10);
    std::vector<int> vec(10, 0);
    for (int i = 0; i < 10; i++)
    {
        vec[i] = uniform_dist(e1);
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    bubbleSort(vec);
    return 0;
}