#include "vector_template.h"
#include <iostream>
template <typename T>
void print(T &value)
{
    std::cout << value << std::endl;
}
int main()
{
    unsigned int a = 20;
    Vector<int> testV{a};
    testV.insert(2);
    std::cout << testV.size() << std::endl;
    testV.traverse(&print<int>);
    return 0;
}
