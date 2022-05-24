#include <iostream>


class A
{
public:
    void print()
    {
        std::cout << "Uhuu" << std::endl;
    }

    static void func(void* ctx)
    {
        A* a = (A*) ctx;

        a->print();
    }

    void call()
    {
        func((void*)this);
    }
};

int main()
{
    A* a = new A();
    a->call();
}