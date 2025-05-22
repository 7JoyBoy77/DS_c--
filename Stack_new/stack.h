#include "../Vector_new/vector_template.h"

template <typename T>
class Stack : public Vector<T>
{
public:
    void push(const T &e);
    T pop();
    T &top();
    int size();
    bool empty();
};

template <typename T>
void Stack<T>::push(const T &e)
{
}
template <typename T>
T Stack<T>::pop()
{
}
template <typename T>
T &Stack<T>::top()
{
}
template <typename T>
int Stack<T>::size()
{
}
template <typename T>
bool Stack<T>::empty()
{
}