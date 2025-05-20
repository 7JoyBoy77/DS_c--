#include <iostream>
#include "Sort.h"
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
    // 由于图补充构造,这里构造T类型不用引用
    Vector(int c, int num, T t);
    ~Vector() { delete[] _elem; }
    // 查找
    Rank find(const T &);
    Rank find(const T &, Rank, Rank);
    // 置乱器
    // 插入
    void insert(const T &t) { insert(t, _size); }
    void insert(const T &, Rank);
    // 单个元素删除
    void erase(Rank);
    // 范围删除
    void erase(Rank, Rank);
    T remove(Rank i) { erase(i); };
    // 唯一化 ，无序唯一化，有序唯一化
    void unique();
    // 遍历
    void traverse(void (*visit)(T &));
    template <typename VST>
    void traverse(VST &visit);
    // 是否有序 返回逆序相邻元素对数
    int isorder();
};
