#include <iostream>

class A
{
private:
    int _A;

public:
    A(int a) : _A(a){};
    int getA() {return _A;}
    int getNonVirtual(){return _A;}
    virtual int get(){return _A;}

    virtual int getPure(){};
};

class B : public A
{
protected:
    int _B;

public:
    B(int b) : A(b), _B(b){};
    B(int a,int b) : A(a), _B(b){};
    int getB(){return _B;}

    int get()override{return _B;}
    int getNonVirtual(){return _B;}

    int sum()
    {
        return getA() + getB();
    }

    // int getPure()override{return _B;}; // if getPure is not defined here class B AND class C become abstract class because they don't define the pure function declared in class A
};

class C : public B
{
private:

public:
    C(int a, int b) : B(a,b){};
    // int get()override{get();}

    void print()
    {
        std::cout << get() << std::endl;
    }
    // int getPure()override{return _B;};
};

int main()
{
    B var(3,2);

    std::cout << var.sum() <<std::endl;
    std::cout << var.get() <<std::endl;

    C var2(3,2);

    var2.print();   
    std::cout << var2.get() <<std::endl;

    B var3(10,11);

    std::cout << var3.get() <<std::endl;//it prints 11
    std::cout << var3.getNonVirtual() <<std::endl; //it prints 11,

    A* var4 = &var3;

    std::cout << var4->get() <<std::endl;//it prints 11, because of the polymorphic behavior
    std::cout << var4->getNonVirtual() <<std::endl; //it prints 10, the funtion getNonVirtual isn't virtual

    A var5 = var3;
    std::cout << var5.get() <<std::endl; //it prints 10, because polymophic behavior only works with pointer to base class   
    std::cout << var5.getNonVirtual() <<std::endl; //it prints 10, the funtion getNonVirtual isn't virtual


    B* var6 = new B(20,22);

    std::cout << var6->get() <<std::endl;//it prints 22
    std::cout << var6->getNonVirtual() <<std::endl; //it prints 22,

    A* var7 = var6;

    std::cout << var7->get() <<std::endl;//it prints 22, because of the polymorphic behavior
    std::cout << var7->getNonVirtual() <<std::endl; //it prints 20, the funtion getNonVirtual isn't virtual

    A var8 = *var6;
    std::cout << var8.get() <<std::endl; //it prints 20, because polymophic behavior only works with pointer to base class   
    std::cout << var8.getNonVirtual() <<std::endl; //it prints 20, the funtion getNonVirtual isn't virtual

    C var9(88,99);
    std::cout << var9.getPure() <<std::endl;
}


