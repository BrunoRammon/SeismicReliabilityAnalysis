#include<vector>
#include<iostream>

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
};

const int& func()
{
    const int& a = 4;

    return a;
}

int main()
{   
    A a(1);
    A b(2);
    A c(3);
    const A* e = &a;
    A* const f = &a;
    const A* const g = &a;
    const A h = a;
    const A& i = a;
    A& j = a;
    
    e = &b;
    // e->setA(80); //it does not compile, error message: "passing ‘const A’ as ‘this’ argument discards qualifiers"
    // f = &b; //it does not compile, error message: "assignment of read-only variable ‘f’"
    f->setA(80);
    // g = &b; //it does not compile, error message: "assignment of read-only variable ‘g’"
    // g->setA(80);//it does not compile, error message: "passing ‘const A’ as ‘this’ argument discards qualifiers" 
    // h = b; //it does not compile, error message: "passing ‘const A’ as ‘this’ argument discards qualifiers"
    // h.setA(80);//it does not compile, error message: "passing ‘const A’ as ‘this’ argument discards qualifiers" 
    // i = b; //it does not compile, error message: "passing ‘const A’ as ‘this’ argument discards qualifiers"
    // i.setA(80);//it does not compile, error message: "passing ‘const A’ as ‘this’ argument discards qualifiers" 
    j = b; 
    j.setA(80);

    const std::vector<A*> as0 = {&a,&b,&c};
    std::vector<const A*> as1 = {&a,&b,&c};
    std::vector<A*> const as2 = {&a,&b,&c};
    const std::vector<A> as3 = {a,b,c};
    // std::vector<const A> as4 = {a,b,c}; //it does not compile
    // std::vector<const A> as4; //it does not compile
    std::vector<A> const as5 = {a,b,c};
    
    //first test: check the change of elements in the vectors
    A d(4);
    // as0[0] = &d; // it does not compile, error message: "assignment of read-only location"
    as1[0] = &d;
    // as2[0] = &d;// it does not compile, error message: "assignment of read-only location"
    // as3[0] = d;//it does not compile, error message: "passing ‘const value_type {aka const A}’ as ‘this’ argument discards qualifiers"
    // as5[0] = d;//it does not compile, error message: "passing ‘const value_type {aka const A}’ as ‘this’ argument discards qualifiers"

    //first test: check the change of value in the
    as0[0]->setA(10);
    // as1[0]->setA(10); // it does not compile, error message: "passing ‘const A’ as ‘this’ argument discards qualifiers"
    as2[0]->setA(10);
    // as3[0].setA(20); //it does not compile, error message: "passing ‘const value_type {aka const A}’ as ‘this’ argument discards qualifiers"
    // as5[0].setA(40);//it does not compile, error message: "passing ‘const value_type {aka const A}’ as ‘this’ argument discards qualifiers"

    int numberA = func();

    std::cout << numberA << std::endl;
}