#include<iostream>
#include"Vector_template.h"
template<typename T>

class Stack : public Vector<T>
{
    public:
    void push(T const& e)
    {
        insert(size(), e);
    }
    T& pop()
    {
        return remove(size() - 1);    
    }
    T& top()
    {
        return ((*this)[size() - 1]);
    }
    bool Empty()
    {
        return size();
    }
};