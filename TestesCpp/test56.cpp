#include<unordered_map>
#include <iostream>
#include <vector>


class A
{
private:
    int _a;
protected:
    A* _reverseA = nullptr;
public:
    A(){}
    A(int a)
    : _a(a)
    {
        std::cout << "ConstructorA " << _a << std::endl;
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

    A* getReverseA()
    {
        return _reverseA;
    }

    A* setReverseA(A* reverseA)
    {
        _reverseA = reverseA;
    }


    virtual ~A()
    {

        if(_reverseA != nullptr)
        {
            _reverseA->_reverseA = nullptr;
            std::cout << "Passou aqui" << std::endl;
        }
        delete _reverseA;
        
        std::cout << "DestructorA " << _a << std::endl;
    }

    virtual A* operator-()
    {}

    void printSomething()
    {
        std::cout << "Something " << std::endl;
    }

    virtual void print()
    {
        std::cout << _a << std::endl;
    }
    void printReverse()
    {
        _reverseA->print();
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
    A* aa = new A(20);
    A* bb = new A(10);
    std::unordered_map<A*,A*> a;
    a[aa] = bb;

    A cc;
    cc = A(10);

    cc.print();
}