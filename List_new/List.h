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
