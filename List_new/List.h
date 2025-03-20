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
    List(ListNode *h, ListNode *t, int s) : header(h), trailer(t), _size(s) {}
    // 返回创建的新节点
    ListNode<T> *insertFront(const T &data);
    ListNode<T> *insertLast(const T &data);
    ListNode<T> *insertPre(ListNode<T> *p, const T &data);
    ListNode<T> *insertSuc(ListNode<T> *p, const T &data);
};
