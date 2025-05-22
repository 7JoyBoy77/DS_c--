#pragma once
#include "../List_new/List.h"
template <typename T>
class Queue : public List<T>
{
public:
    void enqueue(const T &e);
    T dequeue();
    T top();
    bool empty();
    T front();
};
