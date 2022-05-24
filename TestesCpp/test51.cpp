
#include <iostream>

class A
{
private:
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
        std::cout << "Destructor1" << std::endl;
    }

    void print()
    {
        std::cout << _a << std::endl;
    }
    int operator=(const A& instanceA)
    {
        _a = instanceA._a;
        std::cout << "Assignment operator" << std::endl;

        return -1;
    }
};

int main()
{
    A* aa = new A(3);

    A* bb = new A(5);

    A* cc = new A(*aa);

    A* dd = new A(aa);

    bb->print();

    std::cout << (*bb = *aa) << std::endl;

    delete aa;
    aa = nullptr;
    aa->print();

    bb->print();

    cc->print();
    dd->print();
}