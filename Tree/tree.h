#include "node.h"
#include "../Stack_new/stack.h"
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

    // ������� �� �� ��
    template <typename VST>
    void traverse(BinNode<T> *bn, VST &visit);
    // ������������

    // ��α���
    void traverseLevel();
};
