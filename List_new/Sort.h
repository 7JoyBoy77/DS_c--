#include <iostream>
#include "List.h"
//  需要修改 排序写法也可以这样写，先找到不大于data的最后者
// 遍历，当前元素与前面对比大小 如果 大于了就插在这里
template <typename T>
void insertSort(ListNode<T> *p, unsigned int num)
{

    for (int i = 0; i < num; i++)
    {
        ListNode<T> *temp = p;
        for (int j = i - 1; j >= 0; j--)
        {
            // 这样两两交换不如直接找到然后插入
            if ((temp->data) > ((temp->pre)->data))
            {
                insertPoint(temp, p->data);
                p = p->suc;
                remove(p->pre);
                break;
                // 交换data不行，直接删除一个节点+插入一个节点
                // std::swap(p->data, p->pre->data);
            }
            temp = temp->pre;
        }
    }
}

template <typename T>
void selectSort(ListNode<T> *p, unsigned int num)
{
}

// 二路归并