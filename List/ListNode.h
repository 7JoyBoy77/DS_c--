#include <iostream>
using namespace std;
typedef int Rank;
#define ListNodePosi(T) ListNode<T> *

template <typename T>
class ListNode
{
    //  双向链表的结构构造结点
public:
    T data;
    ListNodePosi(T) pred;
    ListNodePosi(T) succ;

    //  构造器
    ListNode() : data(), pred(nullptr), succ(nullptr) {}
    ListNode(T e, ListNodePosi(T) p = nullptr, ListNodePosi(T) s = nullptr) : data(e), pred(p), succ(s)
    {
    }

    // 接口
    // 前插入
    ListNodePosi(T) insertAsPred(T const &e);
    // 后插人
    ListNodePosi(T) insertAsSucc(T const &e);
};
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const &e)
{
    ListNodePosi(T) x = new ListNode(e, this->pred, this);
    // pred->succ = x;
    // 注意节点链接顺序
    this->pred->succ = x;
    this->pred = x;
    return x;
}

template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const &e)
{
    ListNode(T) x = new ListNode(e, this, this->succ);
    this->succ->pred = x;
    this->succ = x;
}
