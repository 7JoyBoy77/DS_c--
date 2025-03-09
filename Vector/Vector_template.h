#include <iostream>
using namespace std;
// typedef int Rank;
using Rank = int;
#define DEFAULT_CAPACITY 3

template <typename T>
class Vector
{
private:
    Rank _size;
    int _capacity;
    T *_elem; // 规模,容量，数据区

protected:
    // 这是基于“复制”的Vector Constructor  C++无法传递一个数组，本质上传一个指针
    void copyFrom(T *const A, Rank lo, Rank hi);
    // 扩容
    void expand();
    // 收缩
    void shrink();

public:
    Vector<T> &operator=(Vector<T> const &);
    //  动态创建的空间析构掉    数据区是_elem只需析构_elem,_capacity和_size是内部变量会作为对象自身被析构
    ~Vector() { delete[] _elem; }
    // 在没有给数据区对象重载[]下标形式时，是无法使用的。在扩容收缩方法中已经 new T[]了
    T &operator[](int r) const; // const类型，使其无法修改元素值。
    // 判等器
    Rank find(const T &A, Rank lo, Rank hi) const;
    // 插入
    Rank insert(Rank r, const T &e);
    // 删除
    int remove(Rank lo, Rank hi);
    T remove(Rank r);
    Rank size() { return _size; }
    T &operator[](int r) const;
    // void permute(Vector<T> & V);
    void unsort(Rank lo, Rank hi);
    int deduplicate();
};
