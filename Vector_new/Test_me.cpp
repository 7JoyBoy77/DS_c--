#include "vector_template.h"
#include <iostream>
int main()
{
    unsigned int a = 20;
    Vector<int> testV{a};
    std::cout << testV.size() << std::endl;
    return 0;
}