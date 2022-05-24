#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <boost/container_hash/hash.hpp>


class A
{
public:
    A(){};
};

class B : public A
{
public:
    B()
    :A(){}
    virtual int func() = 0;
    int func2();
};

class C : public B
{
public:
    C()
    :B(){}
    int func() override {};
    int funcC(){};
};
int main()
{
    A* a = new C();

    // a->func();
}