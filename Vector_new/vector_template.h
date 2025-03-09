#include <iostream>
#define DEFAULT_CAPACITY 3
typedef int Rank;
template <typename T>
// template <typename VST>
class Vector
{
private:
    unsigned capacity;
    Rank _size;
    T *_elem;

protected:
    void copy(T *const A, Rank lo, Rank hi);
    // 扩容缩容前判断 assert
    void expand();
    void shrink();

public:
    Vector(unsigned cap = DEFAULT_CAPACITY);
    // 拷贝构造Vector
    Vector(const Vector<T> &vec);
    // 基于内置数组的构造
    Vector(T *const A, Rank lo, Rank hi);
    ~Vector() { delete[] _elem };
    // 查找
    Rank find(const T &);
    Rank find(const T &, Rank, Rank);
    // 置乱器
    // 插入
    void insert(const T &, Rank);
    // 单个元素删除
    void erase(Rank);
    // 范围删除
    void erase(Rank, Rank);
    // 唯一化 ，无序唯一化，有序唯一化
    void unique();
    // 遍历
    void traverse(void (*visit)(T &));
    template <typename VST>
    void traverse(VST &visit);
    // 是否有序 返回逆序相邻元素对数
    int isorder();
};
