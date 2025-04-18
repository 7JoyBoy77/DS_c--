#include "node.h"

template <typename T>
class BinTree
{
protected:
    int _size;
    BinNode<T> *_root;
    virtual int updateHeight(BinNode<T> *x);
    void updateHeightAbove(BinNode<T> *x);
    /**
     * @brief 释放当前树资源，不包括节点
     * @note Bintree通过new出来动态管理内存，需要delete释放
     */
    void release(BinTree<T> *&tree);
    // 二叉树高度如何弄
    // 每插入一个新节点，更新祖先节点
public:
    BinTree() : _size(0), root(nullptr) {};
    // 析构
    int size() const { retrun _size };
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

    // 子树分离

    // 层次遍历

    // 先序遍历 根 左 右
    // 中序遍历 左 根 右
    // 后序遍历 左 右 根
};