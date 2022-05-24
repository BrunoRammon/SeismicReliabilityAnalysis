
#include<unordered_map>
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
        std::cout << "Destructor1" << std::endl;
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
    std::unordered_map<A*,A*> mapA;
    A* aa = new A(3);
    A* bb = new A(6);
    A* cc = new A(8);
    A* dd = new A(16);

    A* ee = new B(10);
    A* ff = new B(20);


    mapA[aa] = bb;
    mapA[cc] = dd; 
    mapA[ee] = ff;

    mapA.at(aa)->print();
    mapA.at(cc)->print();
    mapA.at(ee)->print();  
}