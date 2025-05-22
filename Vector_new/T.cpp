#pragma once
typedef int Rank;
// 节点类模版
template <typename T>
class ListNode
{
private:
    ListNode<T> *pre;
    ListNode<T> *suc;
    T data;

public:
    ListNode() = default;
    ListNode(T d, ListNode<T> *p = nullptr, ListNode<T> *s = nullptr) : data(d), pre(p), suc(s) {}

    // 使用引用传递，深拷贝
    ListNode<T> *insertPre(const T &data);
    ListNode<T> *insertSuc(const T &data);
    T data() { return this->data; }
};

// P节点调用
template <typename T>
ListNode<T> *ListNode<T>::insertPre(const T &data)
{
    // ListNode *x(data,this.pre, this);
    // this.pre -> = ln;
    // this. = *this;
    ListNode<T> *x = new ListNode(data, this->pre, this);
    this->pre->suc = x;
    this->pre = x;
    return x;
}

// 有头尾指针插入节点方法一般化，不然空插入一个节点，
// this指的是要创建的对象 new初始化也要相应修改
// 还是要一个头记录，不然不行，new出来的新节点，前驱后继只能没有了
template <typename T>
ListNode<T> *ListNode<T>::insertSuc(const T &data)
{
    ListNode<T> *n = new ListNode<T>(data, this, this->suc);
    this->suc->pre = n;
    this.suc = n;
    return n;
}
// 双链表
template <typename T>
class List
{
private:
    ListNode<T> *header = nullptr;
    ListNode<T> *trailer = nullptr;
    unsigned int _size = 0;

protected:
    void init();

public:
    List() { init() };
    ~List();
    List(ListNode *h, ListNode *t, int s) : header(h), trailer(t), _size(s) {}
    // 返回创建的新节点
    ListNode<T> *insertFront(const T &data);
    ListNode<T> *insertLast(const T &data);
    ListNode<T> *insertPointPre(ListNode<T> *p, const T &data);
    ListNode<T> *insertPointSuc(ListNode<T> *p, const T &data);
    // find 在范围内查找lo开始的后num个节点
    ListNode<T> *find(const T &data, ListNode<T> *lo, unsigned int num) const;
    // copyNodes
    List<T> copyNodes(ListNode<T> *lo, unsigned int nums);
    // void remove(ListNode<T> *p) 删除指针指向，并销毁空间
    void remove(ListNode<T> *p);
    // 析构函数
    // clear()删除每一个节点
    void clear();
    // unique
    void unique();
    // 借助函数指针机制遍历
    void traverse(void (*visit)(T &));
};

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
List<T>::~List()
{
    clear();
    delete header;
    delete trailer;
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
            // 此处链表传后继是不是有问题 lo变了原来实参怎么样了
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
    return lt;
}

template <typename T>
void List<T>::remove(ListNode<T> *p)
{
    p->pre->suc = p->suc;
    p->suc->pre = p->pre;
    delete p;
    this->_size--;
}

template <typename T>
void List<T>::clear()
{
    // 头指针后继非尾指针时可删
    while (header->suc != trailer)
    {
        remove(header->suc);
    }
}

template <typename T>
void List<T>::unique()
{
    // 未重载 =
    ListNode<T> *ptr = header;
    while ((ptr = ptr->suc) != trailer)
    {
        ListNode<T> *p = find(ptr->data, ptr->suc, _size - 1);
        if (p != nullptr)
        {
            remove(p);
        }
    }
}

template <typename T>
void List<T>::traverse(void (*visit)(T &))
{
    for (ListNode<T> *p = header->succ; p != trailer; p = p->succ)
    {
        visit(p->data);
    }
}
