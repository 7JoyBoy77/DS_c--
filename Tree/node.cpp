
#include "node.h"
template <typename T>
BinNode<T>::BinNode()
{
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->color = RBColor::RB_RED;
    this->height = 0;
    // ×óÊ½¶ÑÁô
    this.npl = 1;
}

template <typename T>
BinNode<T>::BinNode(T e, BinNode<T> *p = nullptr, BinNode<T> *lc = nullptr, BinNode<T> *rc = nullptr, int h = 0, int l = 1, RBColor c = RB_RED) :
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
