#include <iostream>
#include "ListNode.h"
using namespace std;
template <typename T>
class List
{
private:
    int _size;
    ListNodePosi(T) header;  // 头
    ListNodePosi(T) trailer; // 尾

protected:
    void init();
    // 查找函数，p是trailer!!!无需n变量只需循环到header
    int clear();
    // 基于复制的构造新list
    void copyNodes(ListNodePosi(T) p, int n);

public:
    // 具备读写权限，public了   public中的接口细节被封装了，封装的是protected和private的内容
    List() { init(); }
    ListNodePosi(T) find(const T &e, int n);
    // 书上这种方法可以在指定区间，声明未定义
    ListNodePosi(T) find(const T &e, int n, ListNodePosi(T) p);
    // 除对应区间内的元素，与查找一致
    ListNodePosi(T) remove(const T &e, int n, ListNodePosi(T) p);
    // 插入
    ListNodePosi(T) insertAsFirst(T const &e);
    ListNodePosi(T) insertAsLast(T const &e);
    ListNodePosi(T) insertAsBefore(ListNodePosi(T) p, T const &e);
    ListNodePosi(T) insertAsBehind(ListNodePosi(T) p, T const &e);
    // 删除 返回节点data
    T remove(ListNodePosi(T) p);
    // 唯一化
    int deduplicate();
    // 基于remove的析构
    ~List();

public:
};

template <typename T>
void List<T>::init()
{
    _size = 0;
    header = new ListNode<T>();
    trailer = new ListNode<T>();
    header->pred = nullptr, header->succ = trailer;
    trailer->pred = header, trailer->succ = nullptr;
}

template <typename T>
ListNodePosi(T) List<T>::find(const T &e, int n)
{
    ListNodePosi(t) p;
    p = trailer;
    //  0 <= n--的处理让p指向了头节点，直接会返回头，这样的处理
    while (0 <= n--)
    {
        p = p->pred;
        if (p->pred == e)
        {
            break;
        }
    }
    return p;
}
// 从后向前的写法真j8阴间现在先自己改过来
// 改成前驱了
template <typename T>
ListNodePosi(T) List<T>::find(const T &e, int n, ListNodePosi(T) p)
{
    while (n-- >= 0)
    {
        p = p->pred;
        if (e = p.data)
        {
            break;
        }
    }
    return p;
}

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const &e)
{
    _size++;
    return header->insertAsPred(e);
}
template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const &e)
{
    _size++;
    return trailer->insertAsPred(e);
}
template <typename T>
ListNodePosi(T) List<T>::insertAsBefore(ListNodePosi(T) p, T const &e)
{
    _size++;
    return p->insertAsPred(e);
}
template <typename T>
ListNodePosi(T) List<T>::insertAsBehind(ListNodePosi(T) p, T const &e)
{
    _size++;
    return p->insertAsSucc(e);
}
template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n)
{
    this->init();
    for (int i = 0; i < n; i++)
    {
        // Last插入用data即可
        insertAsLast(p->data);
        p = p->succ;
    }
}

template <typename T>
T List<T>::remove(ListNodePosi(T) p)
{
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    // 注意节点释放，长度变化
    delete p;
    _size--;
    return e;
}

template <typename T>
int List<T>::clear()
{
    int old_size = _size;
    while (_size > 0)
    {
        remove(header->succ);
    }
    return old_size;
}

template <typename T>
List<T>::~List()
{
    clear();
    delete header;
    delete trailer;
}

template <typename T>
int List<T>::deduplicate()
{
    // 对find的了解足够才能去进行相关的唯一化
    if (_size < 2)
    {
        return 0;
    }

    int old_size = _size;
    ListNodePosi(T) p = header->succ;
    Rank r = 1;
    while (p != trailer)
    {
        ListNodePosi(T) q = find(p->data, r, p);
        (header != q) ? remove(q) : r++;
        p = p->succ;
    }
    return old_size - _size;
}
