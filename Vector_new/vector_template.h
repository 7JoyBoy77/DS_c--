#pragma once
#include "Sort.h"
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
    // ��������ǰ�ж� assert
    void expand();
    void shrink();

public:
    Vector(unsigned cap = DEFAULT_CAPACITY);
    // ��������Vector
    Vector(const Vector<T> &vec);
    // ������������Ĺ���
    Vector(T *const A, Rank lo, Rank hi);
    // ����ͼ���乹��,���ﹹ��T���Ͳ�������
    Vector(int c, int num, T t);
    ~Vector() { delete[] _elem; }
    // ����
    Rank find(const T &);
    Rank find(const T &, Rank, Rank);
    int size() { return this->_size; }
    // ������
    // ����
    void insert(const T &t) { insert(t, _size); }
    void insert(const T &, Rank);
    // ����Ԫ��ɾ��
    void erase(Rank);
    // ��Χɾ��
    void erase(Rank, Rank);
    T remove(Rank i);
    // Ψһ�� ������Ψһ��������Ψһ��
    void unique();
    // ����
    void traverse(void (*visit)(T &));
    template <typename VST>
    void traverse(VST &visit);
    // �Ƿ����� ������������Ԫ�ض���
    int isorder();
};
template <typename T>
void Vector<T>::copy(T *const A, Rank lo, Rank hi)
{
    _size = 0;
    _elem = new T[capacity = 2 * (hi - lo)];
    while (lo != hi)
    {
        _elem[_size] = A[lo];
        lo++;
        _size++;
    }
}

template <typename T>
Vector<T>::Vector(unsigned cap)
{
    _size = 0;
    this->capacity = cap;
    _elem = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T> &vec)
{
    copy(vec._elem, 0, vec._size);
}

template <typename T>
Vector<T>::Vector(T *const A, Rank lo, Rank hi)
{
    copy(A, lo, hi);
}

template <typename T>
Vector<T>::Vector(int c, int num, T t)
{
    this->capacity = c;
    this->_elem = new T[capacity];
    this->_size = num;
    for (int i = 0; i < _size; i++)
    {
        _elem[i] = t;
    }
}

template <typename T>
void Vector<T>::expand()
{
    T *old_elem = _elem;
    _elem = new T[capacity *= 2];
    for (int i = 0; i < _size; i++)
    {
        _elem[i] = old_elem[i];
    }
    delete[] old_elem;
}

template <typename T>
void Vector<T>::shrink()
{
    T *old_elem = _elem;
    _elem = new T[capacity /= 2];
    for (int i = 0; i < _size; i++)
    {
        _elem[i] = old_elem[i];
    }
    delete[] old_elem;
}

template <typename T>
Rank Vector<T>::find(const T &e)
{
    for (int i = 0; (i < _size); i++)
    {
        if (e == _elem[i])
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
Rank Vector<T>::find(const T &e, Rank lo, Rank hi)
{
    for (int i = lo; (i < hi); i++)
    {
        if (e == _elem[i])
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
void Vector<T>::insert(const T &e, Rank r)
{
    // �Ƿ�����
    for (int i = _size; i > r; i--)
    {
        _elem[i] = _elem[i - 1];
    }
    _elem[r] = e;
    _size++;
}

template <typename T>
void Vector<T>::erase(Rank r)
{
    for (int i = r; i < (_size - 1); i++)
    {
        _elem[i] = _elem[i + 1];
    }
    _size--;
}

template <typename T>
void Vector<T>::erase(Rank lo, Rank hi)
{
    // ��ȷ��Χ�Ķ˵�
    while (hi < _size)
    {
        _elem[lo++] = _elem[hi++];
    }
    _size = lo;
}
template <typename T>
T Vector<T>::remove(Rank i)
{
    T temp = _elem[i];
    erase(i);
    return temp;
}

template <typename T>
void Vector<T>::unique()
{
    for (int i = 1; i < _size; i++)
    {
        Rank j = find(_elem[i], 0, i);
        if (j != -1)
        {
            erase(j);
        }
    }
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T &))
{
    for (int i = 0; i < _size; i++)
    {
        // ����ָ����Func Func(_elem[i]) �÷�����
        // ��ʽ�����ã���ʽ������
        visit(_elem[i]);
    }
}

template <typename T>
template <typename VST>
void Vector<T>::traverse(VST &visit)
{
    for (int i = 0; i < _size; i++)
    {
        visit(_elem[i]);
    }
}

template <typename T>
int Vector<T>::isorder()
{
    int flagNum = 0;
    for (int i = 0; i < (_size - 1); i++)
    {
        if (_elem[i] > _elem[i + 1])
        {
            flagNum++;
        }
    }
    return flagNum;
}