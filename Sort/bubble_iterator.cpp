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
            // swap ���������������ƽ�����ָ���޸�ָ��Ԫ�ص�ֵ
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
        // ���ĳһ��û�з���������˵���Ѿ����򣬿�����ǰ��������
        if (!swapped)
        {
            break;
        }
    }
}

int main()
{
    std::random_device r;
    // ѡ�� 1 �� 10 ��������
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