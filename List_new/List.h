typedef int Rank;

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
};
