#include "vector_template.h"
template <typename T>
Vector<T>::Vector(unsigned cap = DEFAULT_CAPACITY)
{
    this->capacity = cap;
    this->_elem = new T[cap];
    _szie = 0;
    // copy()
}
template <typename T>
Vector<T>::Vector(Vector<T> &vec)
{
    this->capacity = vec.capacity;
    this->_elem = new T[vec.capacity];
    // copy()
}
template <typename T>
// 常量指针
// this明确访问成员变量
void Vector<T>::copy(T *const A, Rank lo, Rank hi)
{
    this->capacity = 2*(hi - lo);
    this->_elem = new T[capacity];
    this->_size = 0;
    while (lo <= hi)
    {
        _elem[_szie] = A[lo]
        lo++;
        _szie++;
    }
}
template <typename T>
/*
数组重新分配大小后，来指向数组元素的指针可能会变得无效。  可能出现野指针。
该 expand 函数正确地管理了 _elem 指针（指向 Vector 内部元素的数组）和 _capacity（数组的当前容量）。
通过先分配新内存，复制数据，然后释放旧内存，它确保了 _elem 始终指向有效的内存区域
避免外部野指针：
然而，这个函数本身并不能防止外部代码创建指向 Vector 内部元素的野指针。
如果外部代码在 Vector 扩容之前保存了一个指向 Vector 内部元素的指针，
并且在扩容之后仍然使用这个指针，那么这个指针就变成了野指针。为了避免这种情况，Vector 类应该提供清晰的文档和接口，
告知使用者不要这样做，或者通过其他机制（如智能指针或迭代器失效检测）来防止。
*/
void Vector<T>::expand()
{
    if (_size < capacity)
    {
        return;
    }
    else
    {
        T *old_elem = _elem;
        _elem = new T [capacity <<= 1];
        for(int i = 0; i < _size ; i++)
        {
            _elem[i] = old_elem[i];
        }
        delete [] old_elem;
    }
}
