#pragma once
typedef int Rank;
// �ڵ���ģ��
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

    // ʹ�����ô��ݣ����
    ListNode<T> *insertPre(const T &data);
    ListNode<T> *insertSuc(const T &data);
    T data() { return this->data; }
};

// P�ڵ����
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

// ��ͷβָ�����ڵ㷽��һ�㻯����Ȼ�ղ���һ���ڵ㣬
// thisָ����Ҫ�����Ķ��� new��ʼ��ҲҪ��Ӧ�޸�
// ����Ҫһ��ͷ��¼����Ȼ���У�new�������½ڵ㣬ǰ�����ֻ��û����
template <typename T>
ListNode<T> *ListNode<T>::insertSuc(const T &data)
{
    ListNode<T> *n = new ListNode<T>(data, this, this->suc);
    this->suc->pre = n;
    this.suc = n;
    return n;
}
// ˫����
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
    // ���ش������½ڵ�
    ListNode<T> *insertFront(const T &data);
    ListNode<T> *insertLast(const T &data);
    ListNode<T> *insertPointPre(ListNode<T> *p, const T &data);
    ListNode<T> *insertPointSuc(ListNode<T> *p, const T &data);
    // find �ڷ�Χ�ڲ���lo��ʼ�ĺ�num���ڵ�
    ListNode<T> *find(const T &data, ListNode<T> *lo, unsigned int num) const;
    // copyNodes
    List<T> copyNodes(ListNode<T> *lo, unsigned int nums);
    // void remove(ListNode<T> *p) ɾ��ָ��ָ�򣬲����ٿռ�
    void remove(ListNode<T> *p);
    // ��������
    // clear()ɾ��ÿһ���ڵ�
    void clear();
    // unique
    void unique();
    // ��������ָ����Ʊ���
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
    // ͷָ���̷�βָ��ʱ��ɾ
    while (header->suc != trailer)
    {
        remove(header->suc);
    }
}

template <typename T>
void List<T>::unique()
{
    // δ���� =
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
