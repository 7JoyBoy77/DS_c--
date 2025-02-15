#include <iostream>
#include <array>
#include <random>
// ð������ð������Bubble Sort��Ҳ��һ�ּ�ֱ�۵������㷨��
// ���ظ����߷ù�Ҫ��������У�һ�αȽ�����Ԫ�أ�������ǵ�˳�����Ͱ����ǽ����������߷����еĹ������ظ��ؽ���ֱ��û������Ҫ������Ҳ����˵�������Ѿ�������ɡ�
// ����㷨��������������ΪԽС��Ԫ�ػᾭ�ɽ�������"��"�����еĶ��ˡ�
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