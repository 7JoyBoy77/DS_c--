
#include "Vector_template.h"

template <typename T>
void Vector<T>::copyFrom(T *const A, Rank lo, Rank hi)
{
    // 顺便给_capacity赋值，一举两得
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo != hi)
    {
        _elem[_size++] = A[lo++];
    }
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &V)
{
    int n = V.size();
    if (_capacity < n)
    {
        delete[] _elem;
        _elem = new T[_capacity = 2 * n];
    }
    copyFrom(V.elem, 0, n);
    return *this;
}

template <typename T>
void Vector<T>::expand()
{
    // 当_size++以后_size == _capacity时就需要调用expand()函数，所以此时_size和_capacity两个变量的意义出现了。
    // 即在插入之前调用expand()就可以做到。
    if (_size < _capacity)
        return;
    if (_capacity < DEFAULT_CAPACITY)
        _capacity = DEFAULT_CAPACITY;
    T *old_elem = _elem;
    _elem = new T[_capacity <<= 1];
    for (int i = 0; i < _size; i++)
    {
        _elem[i] = old_elem[i];
    }
    delete[] old_elem;
}
template <typename T>
void Vector<T>::shrink()
{
    // 收缩会收缩到原来的1/2，但是不会收缩到DEFAULT_CAPACITY以下
    if (_capacity < DEFAULT_CAPACITY << 1)
        return;
    if (_size << 2 > _capacity)
        return;
    T *old_elem = _elem;
    _elem = new T[_capacity >>= 1];
    for (int i = 0; i < _size; i++)
    {
        _elem[i] = old_elem[i];
    }
    delete[] old_elem;
}

template <typename T>
T &Vector<T>::operator[](int r) const
{
    // 注意r的范围，若r > Rank或者r < 0要报错
    return _elem[r];
}

template <typename T>
Rank Vector<T>::find(const T &A, Rank lo, Rank hi) const
{
    // 从后往前所以hi--
    while ((lo < hi--) && (_elem[hi] != A))
        ;
    // 若hi < lo,即没有找到,返回-1
    return hi;
}
template <typename T>
Rank Vector<T>::insert(Rank r, const T &e)
{
    expand();
    for (int i = _size; i > r; i--)
    {
        _elem[i] = _elem[i - 1];
    }
    _elem[r] = e;
    _size++;
    return r;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi)
        return 0;
    while (hi < _size)
    {
        _elem[lo++] = _elem[hi++];
    }
    _size = lo;
    shrink();
    return hi - lo;
}
template <typename T>
T Vector<T>::remove(Rank r)
{
    T e = _elem[r];
    remove(r, r + 1);
    return e;
}

template <typename T>
static Rank binarSearch(const T *A, const T &e, Rank lo, Rank hi)
{
    while (hi >= lo)
    {
        Rank mi = (lo + hi) << 1;
        if (e < A[mi])
        {
            hi = mi - 1;
        }
        else if (e > A[mi])
        {
            lo = mi + 1;
        }
        else
        {
            return mi;
        }
    }
    return -1;
}

template <typename T>
T &Vector<T>::operator[](int r) const
{
    return _elem[r];
}
/*
template <typename T>
将这个算法封装进ADT中，对外提供unsort接口
void Vector<T>::permute(Vector<T> &V)
{
    for (int i = V.size(); i > 0 ; i--)
    {
        swap(V[i-1], V[rand()% i]);
    }
}
*/
template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi)
{
    T *V = _elem + lo;
    for (int i = hi - lo; i > 0; i--)
    {
        swap(V[i - 1], V[rand() % i]);
    }
}

template <typename T>
int Vector<T>::deduplicate()
{
    int oldSize = _size;
    int i = 1;
    while (i < _size)
    {
        Rank j = find(_elem[i], 0, i);
        /* code */
    }
}