#include<iostream>

class A{};

int main()
{
    A* a = nullptr;
    if(a)
    {
        std::cout << std::boolalpha << true << std::endl;
    }
    else
    {
        std::cout << std::boolalpha << false << std::endl;
    }

    a= new A();
    if(a)
    {
        std::cout << std::boolalpha << true << std::endl;
    }
    else
    {
        std::cout << std::boolalpha << false << std::endl;
    }
}