#include <iostream>
#include <vector>


class A
{
private:
    int _a;
protected:
    A* _reverseA = nullptr;
public:
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

class B : public A
{
private:
    int _b;
public:
    B(int b)
    : A(b/2),_b(b)
    {
        std::cout << "ConstructorB " << _b << std::endl;
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
        std::cout << "DestructorB " << _b << std::endl;
    }

    A* operator-() override
    {
        if(_reverseA == nullptr)
        {
            _reverseA = new B(-(this->_b));

            (_reverseA->setReverseA(this));
            std::cout << "Passou" << std::endl;
            return _reverseA;
        }
        else
        {
            return _reverseA;
        } 

    }

    // int soma() override
    // {
    //     return _a+_b;
    // }
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
    A* b = new B(50);
    -(*b);
    
    b->print();
    b->printReverse();

    delete b;
    // delete b;
    
    std::cin.get();
}