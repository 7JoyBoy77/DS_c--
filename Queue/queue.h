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