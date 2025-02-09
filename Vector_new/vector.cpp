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
// ����ָ��
// this��ȷ���ʳ�Ա����
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
�������·����С����ָ������Ԫ�ص�ָ����ܻ�����Ч��  ���ܳ���Ұָ�롣
�� expand ������ȷ�ع����� _elem ָ�루ָ�� Vector �ڲ�Ԫ�ص����飩�� _capacity������ĵ�ǰ��������
ͨ���ȷ������ڴ棬�������ݣ�Ȼ���ͷž��ڴ棬��ȷ���� _elem ʼ��ָ����Ч���ڴ�����
�����ⲿҰָ�룺
Ȼ������������������ܷ�ֹ�ⲿ���봴��ָ�� Vector �ڲ�Ԫ�ص�Ұָ�롣
����ⲿ������ Vector ����֮ǰ������һ��ָ�� Vector �ڲ�Ԫ�ص�ָ�룬
����������֮����Ȼʹ�����ָ�룬��ô���ָ��ͱ����Ұָ�롣Ϊ�˱������������Vector ��Ӧ���ṩ�������ĵ��ͽӿڣ�
��֪ʹ���߲�Ҫ������������ͨ���������ƣ�������ָ��������ʧЧ��⣩����ֹ��
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
