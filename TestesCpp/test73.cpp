#include<iostream>

class A
{
public:
    virtual void func1() const
    {
        std::cout << "func1(): Classe A" << std::endl;
    }
    virtual void func3() const
    {
        func1();
    }
};
class B : public A
{
public:
    void func1() const override
    {
        std::cout << "func1(): Classe B" << std::endl;
    }
    
    void func3() const override
    {
       func2();
    }

    void func4() const
    {
       func2();
    }
private:
    void func2() const
    {
        std::cout << "func2(): Classe B" << std::endl;
    }
};

int main()
{
    B b;
    b.func1();
    b.func4();

    A &a1 = b;
    A* a2 = &b;
    A a3 = b; 
    A a4;
    A* a5 = new B();
    A* a6 = new A();

    std::cout << "=======================================" << std::endl;
    a1.func1();
    a2->func1();
    a3.func1();//print "func1(): Classe A" because, a3 = b is only a copy, this does not result in a polymorphismo
    a4.func1();
    a5->func1();
    a6->func1();

    std::cout << "=======================================" << std::endl;
    a1.func3();
    a2->func3();
    a3.func3();//print "func1(): Classe A" because, a3 = b is only a copy, this does not result in a polymorphismo
    a4.func3();
    a5->func3();
    a6->func3();

    std::cout << "=======================================" << std::endl;
    a1.func4();
    a2->func4();
    a3.func4();//print "func1(): Classe A" because, a3 = b is only a copy, this does not result in a polymorphismo
    a4.func4();
    a5->func4();
    a6->func4();
}