
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpmf-conversions"
#include<iostream>

class A;
int func2(int(A::*funcGetInt)(void), void* ctx);
int func(int(*funcGetInt)(void))
{
    return funcGetInt();
}

class A
{
private:
    int _A;
public:
    A(int a)
    :_A(a)
    {}
    const int& getA() const
    {
        return _A;
    }
    int getAA()
    {
        return _A;
    }
    void setA(int a)
    {
        _A = a;
    }
    // int getA() const
    // {
    //     return _A;
    // }
    A& operator=(const A& a)
    {
        _A = a._A;
        return *this;
    }
    void print(void)
    {
        typedef int (*FUNCType)(void);
        std::cout<< func((FUNCType) &A::getAA)<<std::endl;
    }
    void print2(void)
    {
        typedef int (A::*FUNCType)(void);
        std::cout<< func2((FUNCType) &A::getAA,this)<<std::endl;
    }
};

int func2(int(A::*funcGetInt)(void), void* ctx)
{
    A* a = (A*) ctx;
    return (a->*funcGetInt)();
}


int funcInt()
{
    return 10;
}




int main()
{
    A* a = new A(23);
    
    // std::cout<< func((void*)a)<<std::endl;
    std::cout<< func(funcInt)<<std::endl;
    a->print2();
    a->print();
}