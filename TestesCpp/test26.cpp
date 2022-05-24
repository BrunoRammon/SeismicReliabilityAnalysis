#include <iostream>

class test
{
private:   
    int _a;
public:
    test(){}
    test(int a)
    : _a(a)
    {

    }
    int func(int a)
    {
        static int i = a;
        ++i;
        return i;
    }
    void print()
    {
        std::cout << func(1) << std::endl;
    }
};

int main()
{
    test a;
    a.func(5);
    a.print();
    a.func(2);
    a.print();
    test b;
    b.func(6);
    b.print();
    b.func(9);
    b.print();

    b = test(5);
    b.func(6);
    b.print();
    b.func(9);
    b.print();
}