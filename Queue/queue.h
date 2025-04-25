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
