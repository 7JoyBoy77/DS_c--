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
    // ������
    // ����
    void insert(const T &t) { insert(t, _size); }
    void insert(const T &, Rank);
    // ����Ԫ��ɾ��
    void erase(Rank);
    // ��Χɾ��
    void erase(Rank, Rank);
    T remove(Rank i) { erase(i); };
    // Ψһ�� ������Ψһ��������Ψһ��
    void unique();
    // ����
    void traverse(void (*visit)(T &));
    template <typename VST>
    void traverse(VST &visit);
    // �Ƿ����� ������������Ԫ�ض���
    int isorder();
};
