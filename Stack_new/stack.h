#include "../Vector_new/vector_template.h"

template <typename T>
class Stack : public Vector<T>
{
    void push(const T &e) {};
    T pop();
    T &top();
};
