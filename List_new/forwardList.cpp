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
    // ��ͷ������ʱ���᲻ͣ�ݹ飬ɾ�������ڵ㡣
    // ���׷���ջ���
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
    // ��������ĳ�ڵ�β��ȽϺã����ֱ��������ʱ�临�Ӷȸߣ����ʺ�
    ForwardList<T> *insertSucc(ForwardListNode<T> *ln, const T &e);
};

template <typename T>
ForwardList<T>::ForwardList()
{
    // ����Ĭ�Ϲ��캯��
    this->head = new ForwardListNode<T>();
    _size = 0;
}

template <typename T>
ForwardList<T> *ForwardList<T>::insertSucc(ForwardListNode<T> *ln, const T &e)
{
    _size++;
    return ln->insert(e);
}
