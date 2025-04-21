#ifndef _NODE_H_
#define _NODE_H_

#define IsRoot(x) (!(x).parent)
#define IsLeft(x) ((!IsRoot(x)) && (&(x) == (x).parent->left))
#define IsRight(x) ()

#define stature(p) ((p) ? (p)->height : -1)
/**
 * @brief ���ظ��ڵ���ڵ�ǰ�ڵ��ָ��
 *
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
    BinNode(T e, BinNode<T> *p = nullptr, BinNode<T> *lc = nullptr, BinNode<T> *rc = nullptr, int h = 0, int l = 1, RBColor c = RB_RED);
    ~BinNode();
    int size();
    // �ڵ�������ѷ��ֺ���ı仯��������ﲻ��������������һ������ԣ�һ���нڵ������뿪����������������������ȵĸ߶ȡ�
    BinNode<T> *insertAsLeft(const T &);
    BinNode<T> *insertAsRight(const T &);

    // ���ı���
    // ������α���
    template <typename VST>
    void travelLevel(VST &);
    // �ڵ�ıȽ������е���
private:
    T data;
    int height;
    int npl; // ��ʽ����ʲô
    BinNode<T> *parent;
    BinNode<T> *left;
    BinNode<T> *right;
    RBColor color;
};
#endif