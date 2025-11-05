#include "tree.h"
// œ»–Ú
template <typename T, typename VST>
void Traverse(BinNode<T> *bn, VST &visit)
{

    visit(bn->data);
    Traverse(bn->left, visit);
    Traverse(bn->right, visit);
}

template <typename T, typename VST>
void TraverseI1(BinNode<T> *bn, VST &visit)
{
    Stack<BinNode<T> *> S{};
    while (!S.empty())
    {
        while (bn)
        {
            visit(bn->data);
            if (bn->right)
            {
                S.push(bn->right);
            }
            bn = bn->left;
        }
        bn = S.pop();
    }
}

template <typename T, typename VST>
void TraverseI1(BinNode<T> *bn, VST &visit)
{
    Stack<BinNode<T> *> S{};
    S.push(bn);
    while (!S.empty())
    {
        BinNode<T> *bn_copy = S.top();
        visit(bn_copy->data);
        S.pop();
        if (bn->right)
            S.push(bn->right);
        if (bn->left)
            S.push(bn->left);
    }
}
