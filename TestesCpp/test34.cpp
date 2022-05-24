#include <iostream>

class test
{
private:
    int _memberVar;
public:

    test(int memberVar)
    :_memberVar(memberVar)
    {}
    friend int getMemberVar(test* test);
    int getMemberVar2(){return _memberVar;}
};

int getMemberVar(test* test)
{
    return test->_memberVar;
}

int function(int (*getMember)(test*), test* t)
{
    return (getMember(t)+3);
}

int main()
{
    test a{3};
    std::cout << a.getMemberVar2() << std::endl;
    std::cout << getMemberVar(&a) << std::endl;

    std::cout << function(getMemberVar,&a) << std::endl;
}