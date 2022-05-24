
#include<iostream>

class A
{
private:
    double _a;
public:
    A(const double& a)
    :_a(a)
    {}
    double& getA()
    {
        return _a;
    }
    void setA(double a)
    {
        _a = a;
    }
};

int main()
{
    A* test1 = new A(3.0);

    A* test2 = new A(test1->getA());

    std::cout << test1->getA() << std::endl;
    std::cout << test2->getA() << std::endl;

    test2->setA(5.0);

    std::cout << test1->getA() << std::endl;
    std::cout << test2->getA() << std::endl;
}