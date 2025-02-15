#include <iostream>
#include <array>
#include <random>
// ����������һ�����ֱ�۵������㷨�����Ĺ���ԭ����ͨ�������������У�
// ����δ�������ݣ��������������дӺ���ǰɨ�裬�ҵ���Ӧλ�ò����롣
int main()
{
    // �����ֵ���֣�������
    std::random_device r;
    // ѡ�� 1 �� 6 ��������
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