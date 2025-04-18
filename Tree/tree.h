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
     * @brief �ͷŵ�ǰ����Դ���������ڵ�
     * @note Bintreeͨ��new������̬�����ڴ棬��Ҫdelete�ͷ�
     */
    void release(BinTree<T> *&tree);
    // �������߶����Ū
    // ÿ����һ���½ڵ㣬�������Ƚڵ�
public:
    BinTree() : _size(0), root(nullptr) {};
    // ����
    int size() const { retrun _size };
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

    // ��������

    // ��α���

    // ������� �� �� ��
    // ������� �� �� ��
    // ������� �� �� ��
};