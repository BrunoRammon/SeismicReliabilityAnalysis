#include <iostream>

class test
{
public:
    int _a;

    test(int a):_a(a){}
};

void func(const test* const var)
{
    delete var;
}

int main()
{
    test* var = new test(3);

    std::cout << var->_a << std::endl;

    func(var);

    std::cout << var->_a << std::endl;


    double a = 5;
    double c = 7;

    const double* b = &a;
    std::cout << *b << std::endl;
    
    // *b = c; error: pointer to a const value so the value which b point cannot be changed by the variable b
    b = &c;
    std::cout << *b << std::endl;


    double* const d = &a;
    std::cout << *d << std::endl;

    *d = c;
    // d = &c; error: const pointer. so the pointer d cannot be changed
    std::cout << *d << std::endl;

    c = 9;
    std::cout << *b << std::endl;
    a = 11;
    std::cout << *d << std::endl;


}