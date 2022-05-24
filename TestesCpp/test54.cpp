#include <iostream>
#include <vector>


class A
{
protected:
    int _a;
public:
    A(int a)
    : _a(a)
    {
        std::cout << "Constructor1" << std::endl;
    }

    A(const A& instanceA)
    :_a(instanceA._a)
    {
        // _a = instanceA._a;
        std::cout << "Copy constructor1" << std::endl;
    }

    A(const A* instanceA)
    :_a(instanceA->_a)
    {
        
        std::cout << "Copy constructor2" << std::endl;
    }

    ~A()
    {
        std::cout << "DestructorA" << std::endl;
    }

    void printSomething()
    {
        std::cout << "Something " << std::endl;
    }

    virtual void print()
    {
        std::cout << _a << std::endl;
    }
    int operator=(const A& instanceA)
    {
        _a = instanceA._a;
        std::cout << "Assignment operator" << std::endl;

        return -1;
    }
    virtual int soma() = 0;
};

class B : public A
{
private:
    int _b;
public:
    B(int b)
    : A(b/2),_b(b)
    {
        std::cout << "Constructor1" << std::endl;
    }

    // B(const B& instanceB)
    // :_b(instanceB._b)
    // {
    //     std::cout << "Copy constructor1" << std::endl;
    // }

    // B(const B* instanceB)
    // :_b(instanceB->_b)
    // {
        
    //     std::cout << "Copy constructor2" << std::endl;
    // }

    ~B()
    {
        std::cout << "DestructorB" << std::endl;
    }

    int soma() override
    {
        return _a+_b;
    }
    void print() override
    {
        std::cout << _b << std::endl;
    }
    int operator=(const B& instanceB)
    {
        _b = instanceB._b;
        std::cout << "Assignment operator" << std::endl;

        return -1;
    }
};

int main()
{
    A* b = new B(8);

    b->printSomething();
    b->print();

    std::cout << b->soma() << std::endl;
    delete b;
}