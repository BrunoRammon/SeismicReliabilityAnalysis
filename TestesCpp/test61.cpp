
#include <iostream>
#include <typeinfo>
using namespace std;

struct Resource {
    virtual ~Resource() = default;
};

struct Texture : Resource {};

struct Base {}; // non-polymorphic
struct Derived : Base {};
 
struct Base2 { virtual void foo() {} }; // polymorphic
struct Derived2 : Base2 {};

int main() {
    Resource *resource = new Resource;
    Resource *texture = new Texture;
    
    Texture texture2;

    Resource &texture3 = texture2;

    
    cout << typeid(*resource).name() << endl; // yields 'Resource'
    cout << typeid(*texture).name() << endl; // yields 'Texture'
    cout << typeid(texture2).name() << endl; // yields 'Resource'
    cout << typeid(texture3).name() << endl; // yields 'Texture'

    Derived d1;
    Base& b1 = d1;
    std::string className = typeid(b1).name();
    std::cout << "reference to non-polymorphic base: " << className << '\n';
    std::cout << className.front() << '\n';
    
    Derived2 d2;
    Base2& b2 = d2;
    std::cout << "reference to polymorphic base: " << typeid(b2).name() << '\n';

    return 0;
}