#include <iostream>
#define DEFAULT_CAPACITY 3
typedef int Rank;
template <typename T>
class Vector
{
private:
    unsigned capacity;
    Rank _size;
    T *_elem;
protected:
    void copy(T *const A, Rank lo, Rank hi);
    void expand();      //œÚ¡ø¿©»›
public:
    Vector(unsigned cap = DEFAULT_CAPACITY);
    Vector(Vector<T> &vec);
    ~Vector();
};
