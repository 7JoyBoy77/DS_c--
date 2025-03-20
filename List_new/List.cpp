#include "List.h"
template <typename T>
void List<T>::init()
{
    this->header = new ListNode<T>;
    this->trailer = new ListNode<T>;
    this->_size = 0;
    header->suc = trailer;
    header->pre = nullptr;
    trailer->pre = header;
    trailer->suc = nullptr;
}
template <typename T>
// P节点调用
ListNode<T> *ListNode<T>::insertPre(const T &data)
{
    // ListNode *x(data,this.pre, this);
    // this.pre -> = ln;
    // this. = *this;
    ListNode<T> *x = new ListNode(data, this->pre, this);
    this.pre->succ = x;
    this.pre = x;
}
template <typename T>
ListNode<T> *List<T>::insertPre(ListNode<T> *p, const T &data)
{
    return p->insertPre(data);
}