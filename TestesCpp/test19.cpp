#include <iostream>
#include <typeinfo>

class Parent
{
public:
  virtual ~Parent() = default;
  virtual int getA(){return 3;};
  virtual int getDim(){return 7;};
  int get()
  {
    return getDim();
  }
};

class Child : public Parent
{
private:
    static const int dim = 2;
    int a = 1;
public:
    int getA() override{
        return a;
    }
    int getDim() override
    {
        return dim;
    }
};

int main()
{
    Parent *parent = new Child;
    std::cout << parent->getDim() << std::endl;
    std::cout << parent->get() << std::endl;
    std::cout << typeid(parent).name() << '\n';
    std::cout << typeid(*parent).name() << '\n';
}