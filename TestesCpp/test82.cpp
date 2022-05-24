#include <iostream>


class A;
enum class A::Options
{
    OPTION1,
    OPTION2,
    OPTION3
};

class Base
{
public:
    Base();
    virtual const int& getA() const;
    virtual void setA(int a);
    virtual void print()const;
    virtual void printOption(A::Options op)const;
};
Base::Base(){}
const int& Base::getA()const{}
void Base::setA(int a){}
void Base::print()const{}
void Base::printOption(A::Options op)const{}

class A : public Base
{
public:
    enum class Options;
private:
    int _a;
public:
    A(int a);
    const int& getA() const override;
    void setA(int a)override;
    void print()const override;
    void printOption(Options op)const override;
};



A::A(int a)
:Base() ,_a(a)
{}
const int& A::getA() const 
{
    return _a;
}   
void A::setA(int a)
{
    _a = a;
}
void A::print()const
{
    std::cout << _a << std::endl;
}
void A::printOption(Options op)const
{
    switch (op)
    {
        case Options::OPTION1:
            std::cout << "Option 1 chosen!" << std::endl;
            break;
        case Options::OPTION2:
            std::cout << "Option 2 chosen!" << std::endl;
            break;
        case Options::OPTION3:
            std::cout << "Option 3 chosen!" << std::endl;
            break;
        default:
            std::cout << "Option unavailable!" << std::endl;
            break;
    };
}
using randomName = A;
int main()
{
    // Base* var1 = new A(42);
    // Base* var2 = new randomName(89);
    // var1->print();
    // var2->print();

    A var1(42);
    randomName var2(89);
    var1.print();
    var2.print();
    var1.printOption(A::Options::OPTION1);
    var1.printOption(randomName::Options::OPTION1);
    var2.printOption(randomName::Options::OPTION2);
    var2.printOption(A::Options::OPTION2);
}
