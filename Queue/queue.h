#include "../List/List.cpp"
template <typename T>
class Queue : public List
{
public:
    void enqueue(const T &e);
    T dequeue();
    T top();
    bool empty() { return _size; }
};

#include "../List_new/List.h"

template <typename T>
class Queue : protected List<T>
{
public:
    Queue();
    ~Queue();
    void enqueue();
    T dequeue();
    T front();
};