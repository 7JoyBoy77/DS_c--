#include <iostream>
#include "List.h"
//  ��Ҫ�޸� ����д��Ҳ��������д�����ҵ�������data�������
// ��������ǰԪ����ǰ��Աȴ�С ��� �����˾Ͳ�������
template <typename T>
void insertSort(ListNode<T> *p, unsigned int num)
{

    for (int i = 0; i < num; i++)
    {
        ListNode<T> *temp = p;
        for (int j = i - 1; j >= 0; j--)
        {
            // ����������������ֱ���ҵ�Ȼ�����
            if ((temp->data) > ((temp->pre)->data))
            {
                insertPoint(temp, p->data);
                p = p->suc;
                remove(p->pre);
                break;
                // ����data���У�ֱ��ɾ��һ���ڵ�+����һ���ڵ�
                // std::swap(p->data, p->pre->data);
            }
            temp = temp->pre;
        }
    }
}

template <typename T>
void selectSort(ListNode<T> *p, unsigned int num)
{

    for (int i = 0; i < num; i++)
    {
        ListNode<T> *min = findMax(p, num - i);
        }
}

template <typename T>
void findMax(ListNode<T> *p, unsigned int num)
{

    ListNode<T> *min = p;
    int i = 0;
    for (ListNode<T> *index = p; i < num; i++, index = index->suc)
    {
        if (index->data < min->data)
        {
            min = index;
        }
    }
    return min;
}
// ��·�鲢