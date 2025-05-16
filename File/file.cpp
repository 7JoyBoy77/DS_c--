#include <iostream>
#include <fstream>
int main()
{
    std::fstream fs{"hello.txt", std::ios_base::out | std::ios_base::trunc};
    fs << "hello" << std::endl;
    fs.close();
    if (fs.is_open())
    {
        std::cout << "open_1" << std::endl;
    }
    fs.open("hello.txt");

    if (fs.is_open())
    {
        std::cout << "open_2" << std::endl;
    }
}
