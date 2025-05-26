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
     * @brief 一个求高度与深度的函数算法
     *
     * @param x
     * @return int
     */
    virtual int updateHeight(BinNode<T> *x);
    void updateHeightAbove(BinNode<T> *x);
    /**
     * @brief 释放当前树资源，不包括节点
     * @note Bintree通过new出来动态管理内存，需要delete释放
     */
    // void release(BinTree<T> *&tree);
    // 二叉树高度如何弄
    // 每插入一个新节点，更新祖先节点
public:
    BinTree() : _size(0), root(nullptr) {};
    // 析构
    int size() const { return _size };
    // 判空
    bool isEmpty() const { return !_root; }
    // 返回根节点
    BinNode<T> *root() { return _root; }
    // 插入根节点
    BinNode<T> *insertRoot(const T &e);
    // 插入一个左孩子给节点x
    BinNode<T> *insertAsLeft(BinNode<T> *x, const T &e);
    // 插入一个右孩子给节点x
    BinNode<T> *insertAsRight(BinNode<T> *x, const T &e);
    /**
     * @brief 插入一个子树给X节点
     * @return 返回子树根节点
     */
    BinNode<T> *attachAsLeft(BinNode<T> *x, BinTree<T> *&S);
    // 插入一个右子树给节点x
    BinNode<T> *attachAsRight(BinNode<T> *x, BinTree<T> *&S);
    // 删除以x节点为N的子树
    int remove(BinNode<T> *bn);
    static int removeAt(BinNode<T> *bn);
    // 子树分离
    BinTree<T> *secede(BinNode<T> *bn);
    // 层次遍历

    // 先序遍历 根 左 右
    template <typename VST>
    void traversePre(BinNode<T> *bn, VST &visit);
    // 迭代版先序遍历
    template <typename VST>
    static void visitLeftBranch(BinNode<T> *bn, VST &visit, Stack<BinNode<T> *> &S);
    template <typename VST>
    void traversePre_I2(BinNode<T> *bn, VST &visit);

    // 中序遍历 左 根 右
    template <typename VST>
    void traverseIn(BinNode<T> *bn, VST &visit);
    // 迭代版中序遍历
    template <typename VST>
    static void goLeftBranch(BinNode<T> *bn, VST &visit, Stack<BinNode<T> *> &S);
    template <typename VST>
    void traversePre_I1(BinNode<T> *bn, VST &visit);

    template <typename VST>
    void traverseIn_loop(BinNode<T> *bn, VST &visit);
    // 后序遍历 左 右 根
    template <typename VST>
    void traverse(BinNode<T> *bn, VST &visit);
    // 迭代版后序遍历

    // 层次遍历
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
    // 本质上是左右孩子的最大高度 + 1
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
    // 释放树之后，节点不会被释放，只不过，链接过来的S树的节点，被现在的树控制。
    // 之前的树释放，然后就没有控制之前树节点的树了。释放树没有释放节点。
    // Answer
    /**
     * @note
     * 根据 BinTree 类的设计，
     * release 函数的核心功能是断开原树 S 与节点的关联，而非删除节点。
     */
}
template <typename T>
int BinTree<T>::remove(BinNode<T> *bn)
{
    // 避免父节点指向bn的指针成为悬空指针
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
        // 每个子树都要遍历一次
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
先序遍历 由于右树最后遍历所以尾递归的特性无序压栈，
我们只需要将左子树的递归压入栈中 这里没问题
在设计算法时，递归中 “先左后根” 的隐式路径，在迭代中通过 “压栈记录路径→弹出访问根→处理右子树” 显式模拟。
栈保存了所有未访问的根节点，确保左子树完全遍历后才访问根。
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
