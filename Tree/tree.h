#define IsRoot(x) (!(x).parent)
#define IsLeft(x) ()
#define IsRight(x) ()

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
    BinNode(T e, BinNode<T> *p = nullptr, BinNode<T> *l = nullptr, BinNode<T> *r = nullptr, int h = 0, int l = 1, RBColor c = RB_RED);

    ~BinNode();
    int size();
    int heightTree();
    BinNode<T> *insertAsLeft(const T &);
    BinNode<T> *insertAsRight(const T &);

    // ���ı���
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
