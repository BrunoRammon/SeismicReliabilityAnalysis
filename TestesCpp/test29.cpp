#include <vector>
#include <iostream>

class exam
{
private:

public:
    virtual const int& getA() const
    {}
    void printA()
    {
        std::cout<< this->getA() << std::endl;
    }
};
class test : public exam
{
private:
    int _a = 2;
public:
    virtual const int& getA() const override
    {
        return _a;
    }
};
int main()
{
    exam* a = new test();

    std::cout << a->getA() << std::endl;
    a->printA();
}