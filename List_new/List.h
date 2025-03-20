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
    List(ListNode *h, ListNode *t, int s) : header(h), trailer(t), _size(s) {}
    // ���ش������½ڵ�
    ListNode<T> *insertFront(const T &data);
    ListNode<T> *insertLast(const T &data);
    ListNode<T> *insertPre(ListNode<T> *p, const T &data);
    ListNode<T> *insertSuc(ListNode<T> *p, const T &data);
};
