#include "tree.h"
template <typename T>
BinNode<T> *BinTree<T>::insertRoot(const T &e)
{
    _size = 1;
    BinNode<T> *bn = new BinNode(e);
    this->_root = bn;
    return bn;
}

template <typename T>
void BinTree<T>::release(BinTree<T> *&tree)
{
}

template <typename T>
int BinTree<T>::updateHeight(BinNode<T> *x)
{
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
    updateHeightAbove(bn->parent);
    BinTree<T> *S = new BinTree;
    // S->_size = bn->size;
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
        x = S.pop();
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

template <typename T>
template <typename VST>
void BinTree<T>::traversePre_I1(BinNode<T> *bn, VST &visit)
{
    Stack<BinNode<T> *> S;
    while (true)
    {
        goLeftBranch(bn, visit, S);
        // if(S.empty()) break;
        bn = S.pop();
        visit(data);
        bn = bn->right;
    }
}

template <typename T>
void BinTree<T>::traverseLevel()
{
    queue<BinNode<T> *> Q{};
    Q.push(t);
    while (!Q.empty())
    {
        BinNode<T> *bn = Q.pop();
        visit(bn);
        // �����Һ��ӿ�ʼ��������
        //
    }
}