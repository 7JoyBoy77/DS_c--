#include <iostream>
#include <array>
#include <random>
// ѡ������������δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ�á�
// �ٴ�ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ��
// �ظ��ڶ�����ֱ������Ԫ�ؾ�������ϡ�
int main()
{
    // �����ֵ���֣�������
    std::random_device r;
    // ѡ�� 1 �� 6 ��������
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