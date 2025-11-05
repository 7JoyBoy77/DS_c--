template <typename T>
class ForwardListNode
{
public:
    ForwardListNode();
    ForwardListNode(const T &e) : data(e), succ(nullptr) {};
    ~ForwardListNode();
    ForwardListNode<T> *insert(const T &e);

private:
    T data;
    ForwardListNode<T> *succ;
};
template <typename T>

ForwardListNode<T>::ForwardListNode()
{
    this->succ = nullptr;
}
template <typename T>
ForwardListNode<T>::~ForwardListNode()
{
    // 当头结点调用时，会不停递归，删除后续节点。
    // 容易发生栈溢出
    delete succ;
}
template <typename T>
ForwardListNode<T> *ForwardListNode<T>::insert(const T &e)
{
    ForwardListNode<T> *x = new ForwardListNode<T>(e);
    x->succ = this->succ;
    this->succ = x;
    return x;
}
template <typename T>
class ForwardList
{
private:
    ForwardListNode<T> *head;
    int _size;

public:
    ForwardList();
    ForwardList<T> *insertSucc(ForwardListNode<T> *ln, const T &e);
};

template <typename T>
ForwardList<T>::ForwardList()
{
    // 调用默认构造函数
    this->head = new ForwardListNode<T>();
    _size = 0;
}

/**
 * @brief
 *
 * @tparam T
 * @param ln
 * @param e
 * @return ForwardList<T>*
 */
template <typename T>
ForwardList<T> *ForwardList<T>::insertSucc(ForwardListNode<T> *ln, const T &e)
{
    _size++;
    return ln->insert(e);
}

int (*func_ptr)(int);