#ifndef _STACK_
#define _STACK_
#include<iostream>
#include"Vector_template.h"
#include"Vector.cpp"
template<typename T>
class Stack : public Vector<T>
{
    public:
    void push(const T & e)
    {
        Vector<T>::insert(Vector<T>::size(), e);
    }
    T pop()
    {
        return Vector<T>::remove(Vector<T>::size() - 1);    
    }
    T top()
    {
        return ((*this) [Vector<T>::size() - 1]);
    }
    bool Empty()
    {
        return Vector<T>::size();
    }
};
#endif