#include "node.h"
#include <iostream>
#include <utility>

class Mem
{
private:
    double a;
    int b;
};
int main()
{
    Mem *obj = new Mem();
    std::cout << sizeof(*(obj)) << std::endl;
    return 0;
}
