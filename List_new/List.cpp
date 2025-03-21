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
// P�ڵ����
ListNode<T> *ListNode<T>::insertPre(const T &data)
{
    // ListNode *x(data,this.pre, this);
    // this.pre -> = ln;
    // this. = *this;
    ListNode<T> *x = new ListNode(data, this->pre, this);
    this.pre->succ = x;
    this.pre = x;
    return n;
}
// ��ͷβָ�����ڵ㷽��һ�㻯����Ȼ�ղ���һ���ڵ㣬
// thisָ����Ҫ�����Ķ��� new��ʼ��ҲҪ��Ӧ�޸�
// ����Ҫһ��ͷ��¼����Ȼ���У�new�������½ڵ㣬ǰ�����ֻ��û����
template <typename T>
ListNode<T> *ListNode<T>::insertSuc(const T &data)
{
    ListNode<T> n = new ListNode<T>(data, this, this->suc);
    this->suc->pre = n;
    this.suc = n;
    return n;
}

template <typename T>
ListNode<T> *List<T>::insertFront(const T &data)
{
    // ListNode<T> *ptr = new ListNode<T>(data, this->header, this->header->suc);
    // this->header->suc->pre = ptr;
    // this->header->suc = ptr;
    _size++;
    return header->insertSuc(data);
}
template <typename T>
ListNode<T> *List<T>::insertLast(const T &data)
{
    this->_size++;
    return trailer->insertPre(data);
}

template <typename T>
ListNode<T> *List<T>::insertPointPre(ListNode<T> *p, const T &data)
{
    this->_size++;
    return p->insertPre(data);
}

template <typename T>
ListNode<T> *List<T>::insertPointSuc(ListNode<T> *p, const T &data)
{
    this->_size++;
    return p->insertSuc(data);
}

template <typename T>
ListNode<T> *List<T>::find(const T &data, ListNode<T> *lo, unsigned int num) const
{
    while (num > 0 && lo != nullptr)
    {
        if ((lo->data) != data)
        {
            // �˴���������ǲ��������� lo����ԭ��ʵ����ô����
            lo = lo->suc;
            num--;
        }
        else
        {
            return lo;
        }
    }
    return nullptr;
}

template <typename T>
List<T> List<T>::copyNodes(ListNode<T> *lo, unsigned int nums)
{
    List<T> lt = new List<T>();
    while (nums > 0)
    {
        lt.insertLast(lo->data);
        lo = lo->suc;
    }
}

template <typename T>
void List<T>::remove(ListNode<T> *p)
{
    p->pre->suc = p->suc;
    p->suc->pre = p->pre;
    this->_size--;
    delete p;
}
