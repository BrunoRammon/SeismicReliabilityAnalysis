#include <iostream>
#include <vector>



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

    virtual void print()
    {
        std::cout << "Hey" << std::endl;
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
    A* bb = new A(6);
    A* cc = new A(8);
    A* dd = new A(16);

    std::cin.get();

    A ff(55);
    for(int i  = -3; i<0; ++i)
    {
        ff = A(i);
    }
    ff.print();

    std::cin.get();

    A* gg = new A(100);
    std::vector<A*> vec2 = {gg};
    std::vector<A*> vec3 = {gg};
    vec2[0]->print();
    vec3[0]->print();
    delete vec2[0];
    vec2[0] = nullptr;
    std::cout << true << std::endl;
    std::cout << (vec3[0] == nullptr) << std::endl;
    delete vec3[0];
    std::cout << true << std::endl;
    vec3[0] = nullptr;
    std::cout << true << std::endl;
    gg->print();
    std::cout << true << std::endl;
    std::cout << (gg==nullptr) << std::endl;
    std::cin.get();

    std::vector<A*> vec = {aa,bb,cc,dd};

    for(A* elem: vec)
    {
        elem->print();
    }    

    for(A* elem: vec)
    {
        delete elem;
        elem = nullptr;
    }

    A* ee = new A(20);

    ee->print();

    delete ee;
    ee=nullptr;

    delete ee;

    std::cout << "Passou" << std::endl;

    delete ee;

    std::cout << "Passou" << std::endl;

    ee->print();

    for(A* elem: vec)
    {
        std::cout << "Hey" << std::endl;
        elem->print();
    }

    
}