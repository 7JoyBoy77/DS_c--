#ifndef _NODE_H_
#define _NODE_H_

#define IsRoot(x) (!(x).parent)
#define IsLeft(x) ((!IsRoot(x)) && (&(x) == (x).parent->left))
#define IsRight(x) ()

#define stature(p) ((p) ? (p)->height : -1)
/**
 * @brief 返回父节点关于当前节点的指针
 * @param
 */
#define fromParent(x) (IsRoot(x) ? _root : (IsLeft(x) ? (x).parent->left : (x).parent->right))
enum class RBColor
{
    RB_RED = 0,
    RB_BLACK = 1
};

template <typename T>
class BinNode
{
public:
    BinNode();
    BinNode(T e, BinNode<T> *p = nullptr, BinNode<T> *lc = nullptr, BinNode<T> *rc = nullptr, int h = 0, int l = 1, RBColor c = RBColor::RB_RED);
    ~BinNode();
    int size();
    // 节点自身很难发现后代的变化，因此这里不妨反过来采用另一处理策略：一旦有节点加入或离开二叉树，则更新其所有祖先的高度。
    BinNode<T> *insertAsLeft(const T &);
    BinNode<T> *insertAsRight(const T &);

    // 树的遍历
    // 子树层次遍历
    template <typename VST>
    void travelLevel(VST &);
    // 节点的比较器，判等器
private:
    T data;
    int height;
    int npl; // 左式堆是什么
    BinNode<T> *parent;
    BinNode<T> *left;
    BinNode<T> *right;
    RBColor color;
};
#endif

template <typename T>
BinNode<T>::BinNode()
{
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->color = RBColor::RB_RED;
    this->height = 0;
    // 左式堆留
    this.npl = 1;
}

template <typename T>
BinNode<T>::BinNode(T e, BinNode<T> *p, BinNode<T> *lc, BinNode<T> *rc, int h, int l, RBColor c)
{
    this->data = e;
    this->parent = p;
    this->left = lc;
    this->height = h;
    this->npl = l;
    this->color = c;
}

template <typename T>
BinNode<T> *BinNode<T>::insertAsLeft(const T &e)
{
    BinNode<T> *bn = new BinNode(e, this);
    this->left = bn;
    return bn;
}

template <typename T>
BinNode<T> *BinNode<T>::insertAsRight(const T &e)
{
    BinNode<T> *bn = new BinNode(e, this);
    this->right = bn;
    return bn;
}

template <typename T>
template <typename VST>
void BinNode<T>::travelLevel(VST &visit)
{
}
