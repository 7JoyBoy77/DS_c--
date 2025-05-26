#include "node.h"
#include "../Stack_new/stack.h"
#include "../Queue/queue.h"
template <typename T>
class BinTree
{
protected:
    int _size;
    BinNode<T> *_root;
    /**
     * @brief һ����߶�����ȵĺ����㷨
     *
     * @param x
     * @return int
     */
    virtual int updateHeight(BinNode<T> *x);
    void updateHeightAbove(BinNode<T> *x);
    /**
     * @brief �ͷŵ�ǰ����Դ���������ڵ�
     * @note Bintreeͨ��new������̬�����ڴ棬��Ҫdelete�ͷ�
     */
    // void release(BinTree<T> *&tree);
    // �������߶����Ū
    // ÿ����һ���½ڵ㣬�������Ƚڵ�
public:
    BinTree() : _size(0), root(nullptr) {};
    // ����
    int size() const { return _size };
    // �п�
    bool isEmpty() const { return !_root; }
    // ���ظ��ڵ�
    BinNode<T> *root() { return _root; }
    // ������ڵ�
    BinNode<T> *insertRoot(const T &e);
    // ����һ�����Ӹ��ڵ�x
    BinNode<T> *insertAsLeft(BinNode<T> *x, const T &e);
    // ����һ���Һ��Ӹ��ڵ�x
    BinNode<T> *insertAsRight(BinNode<T> *x, const T &e);
    /**
     * @brief ����һ��������X�ڵ�
     * @return �����������ڵ�
     */
    BinNode<T> *attachAsLeft(BinNode<T> *x, BinTree<T> *&S);
    // ����һ�����������ڵ�x
    BinNode<T> *attachAsRight(BinNode<T> *x, BinTree<T> *&S);
    // ɾ����x�ڵ�ΪN������
    int remove(BinNode<T> *bn);
    static int removeAt(BinNode<T> *bn);
    // ��������
    BinTree<T> *secede(BinNode<T> *bn);
    // ��α���

    // ������� �� �� ��
    template <typename VST>
    void traversePre(BinNode<T> *bn, VST &visit);
    // �������������
    template <typename VST>
    static void visitLeftBranch(BinNode<T> *bn, VST &visit, Stack<BinNode<T> *> &S);
    template <typename VST>
    void traversePre_I2(BinNode<T> *bn, VST &visit);

    // ������� �� �� ��
    template <typename VST>
    void traverseIn(BinNode<T> *bn, VST &visit);
    // �������������
    template <typename VST>
    static void goLeftBranch(BinNode<T> *bn, VST &visit, Stack<BinNode<T> *> &S);
    template <typename VST>
    void traversePre_I1(BinNode<T> *bn, VST &visit);

    template <typename VST>
    void traverseIn_loop(BinNode<T> *bn, VST &visit);
    // ������� �� �� ��
    template <typename VST>
    void traverse(BinNode<T> *bn, VST &visit);
    // ������������

    // ��α���
    void traverseLevel();
};

template <typename T>
BinNode<T> *BinTree<T>::insertRoot(const T &e)
{
    _size = 1;
    BinNode<T> *bn = new BinNode(e);
    this->_root = bn;
    return bn;
}

/*
template <typename T>
void BinTree<T>::release(BinTree<T> *&tree)
{
}
*/

template <typename T>
int BinTree<T>::updateHeight(BinNode<T> *x)
{
    // �����������Һ��ӵ����߶� + 1
    return x->height = 1 + std::max(stature(x->left), stature(x->right)))
}

template <typename T>
void BinTree<T>::updateHeightAbove(BinNode<T> *x)
{
    while (x)
    {
        updateHeight(x);
        x = x->parent;
    }
}

template <typename T>
BinNode<T> *BinTree<T>::insertAsLeft(BinNode<T> *x, const T &e)
{
    x->insertAsLeft(e);
    this->_size++;
    updateHeightAbove(x);
    return (x->left);
}

template <typename T>
BinNode<T> *BinTree<T>::insertAsRight(BinNode<T> *x, const T &e)
{
    x->insertAsRight(e);
    this->_size++;
    updateHeightAbove(x);
    return (x->right);
}

template <typename T>
BinNode<T> *BinTree<T>::attachAsLeft(BinNode<T> *x, BinTree<T> *&S)
{
    if ((x->left = S->_root) != nullptr)
    {
        S->_root->parent = x;
    }
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = nullptr;
    S->_size = 0;
    // release(S);
    // delete S;
    S = nullptr;
    return x->left;
    // �ͷ���֮�󣬽ڵ㲻�ᱻ�ͷţ�ֻ���������ӹ�����S���Ľڵ㣬�����ڵ������ơ�
    // ֮ǰ�����ͷţ�Ȼ���û�п���֮ǰ���ڵ�����ˡ��ͷ���û���ͷŽڵ㡣
    // Answer
    /**
     * @note
     * ���� BinTree �����ƣ�
     * release �����ĺ��Ĺ����ǶϿ�ԭ�� S ��ڵ�Ĺ���������ɾ���ڵ㡣
     */
}
template <typename T>
int BinTree<T>::remove(BinNode<T> *bn)
{
    // ���⸸�ڵ�ָ��bn��ָ���Ϊ����ָ��
    fromParent(*bn) = nullptr;
    updateHeightAbove(bn->parent);

    int n = removeAt(bn);
    this->_size -= n;
    return n;
}

template <typename T>
int BinTree<T>::removeAt(BinNode<T> *bn)
{
    if (!bn)
    {
        return 0;
    }
    int n = 1 + removeAt(bn->left) + removeAt(bn->right);
    delete bn;
    return n;
}

template <typename T>
BinTree<T> *BinTree<T>::secede(BinNode<T> *bn)
{
    fromParent(*bn) = nullptr;
    bn->parent = nullptr;
    updateHeightAbove(bn->parent);
    BinTree<T> *S = new BinTree;
    // S->_size = bn->size;
    S->_root = bn;
    S->_size = bn->size();
    this->_size -= S->_size;
    return S;
}

template <typename T>
template <typename VST>
void BinTree<T>::traversePre(BinNode<T> *bn, VST &visit)
{
    if (!bn)
    {
        return;
    }
    visit(bn->data);
    traversePre(bn->left);
    traversePre(bn->right);
}

template <typename T>
template <typename VST>
void BinTree<T>::visitLeftBranch(BinNode<T> *bn, VST &visit, Stack<BinNode<T> *> &S)
{
    while (bn)
    {
        visit(bn->data);
        S.push(bn->right);
        bn = bn->left;
    }
}

template <typename T>
template <typename VST>
void BinTree<T>::traversePre_I2(BinNode<T> *bn, VST &visit)
{
    Stack<BinNode<T> *> S;
    while (true)
    {
        // ÿ��������Ҫ����һ��
        visitLeftBranch(bn, visit, S);
        // if (S.empty) {break;}
        bn = S.pop();
    }
}

template <typename T>
template <typename VST>
void BinTree<T>::traverseIn(BinNode<T> *bn, VST &visit)
{
    if (!bn)
    {
        return;
    }
    traversePre(bn->left);
    visit(bn->data);
    traversePre(bn->right);
}

template <typename T>
template <typename VST>
void BinTree<T>::goLeftBranch(BinNode<T> *bn, VST &visit, Stack<BinNode<T> *> &S)
{
    while (bn)
    {
        S.push(bn->right);
        bn = bn->left;
    }
}
/*
������� ������������������β�ݹ����������ѹջ��
����ֻ��Ҫ���������ĵݹ�ѹ��ջ�� ����û����
������㷨ʱ���ݹ��� ���������� ����ʽ·�����ڵ�����ͨ�� ��ѹջ��¼·�����������ʸ��������������� ��ʽģ�⡣
ջ����������δ���ʵĸ��ڵ㣬ȷ����������ȫ������ŷ��ʸ���
*/
template <typename T>
template <typename VST>
void BinTree<T>::traversePre_I1(BinNode<T> *bn, VST &visit)
{
    Stack<BinNode<T> *> S;
    while (true)
    {
        goLeftBranch(bn, visit, S);
        if (S.empty())
            break;
        bn = S.pop();
        visit(bn->data);
        bn = bn->right;
    }
}

template <typename T>
template <typename VST>
void BinTree<T>::traverseIn_loop(BinNode<T> *bn, VST &visit)
{
    Stack<BinNode<T> *> S{};
    while (true)
    {
        if (bn)
        {
            S.push(bn);
            bn = bn->left;
        }
        else if (!S.empty())
        {
            bn = S.pop();
            visit(bn->data);
            bn = bn->right;
        }
        else
        {
            break;
        }
    }
}

template <typename T>
void BinTree<T>::traverseLevel()
{
    Queue<BinNode<T> *> Q{};
    Q.enqueue(this->_root);
    while (!Q.empty())
    {
        BinNode<T> *bn = Q.dequeue();
        visit(bn->data);
        if (bn->left)
        {
            Q.enqueue(bn.left);
        }
        if (bn->right)
        {
            Q.enqueue(bn->right);
        }
    }
}
