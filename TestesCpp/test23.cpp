#include <iostream>

class test
{
private:
    static const int _a;
public:
    const int& getA() const;
};

const int test::_a = 1;

const int& test::getA() const
{
    return _a;
}


int main()
{   
    test a;
    
    std::cout <<  a.getA() << std::endl;
}