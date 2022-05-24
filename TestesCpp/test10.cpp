#include <iostream>
#include <vector>

bool a = false;
const bool& func()
{
    return a;
}
int main()
{   
    const bool& b = func();
    bool c = func();
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << &a << std::endl;
    std::cout << &b << std::endl;
    std::cout << &c << std::endl;
    
}
