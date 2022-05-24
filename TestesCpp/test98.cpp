#include <iostream>

class Pair {
public:
  int *pa,*pb;
  Pair(int, int);
  Pair(const Pair &);
 ~Pair();
};

Pair::Pair(int a, int b)
{
  std::cout << "Constructed" << std::endl;
  pa = new int(a);
  pb = new int(b);
  std::cout << (pa) << " " << (pb) << std::endl;
  std::cout << *(pa) << " " << *(pb) << std::endl;
}

Pair::Pair(const Pair & p)
{
  std::cout << "Copy Constructed Beggining" << std::endl;
  std::cout << (p.pa) << " " << (p.pb) << std::endl;
  std::cout << *(p.pa) << " " << *(p.pb) << std::endl;
  pa = new int(*p.pa);
  pb = new int(*p.pb);
  std::cout << "Copy Constructed End" << std::endl;
}

Pair::~Pair()
{
  std::cout << "Destructed" << std::endl;
  delete pa;
  delete pb;
}
 
 /* Here is a main() function you can use
  * to check your implementation of the
  * class Pair member functions.
  */
  
int main() {
  Pair p(15,16);
  std::cout << (p.pa) << " " << (p.pb) << std::endl;
  std::cout << *(p.pa) << " " << *(p.pb) << std::endl;
  Pair q(p);
  std::cout <<"Oxe: "<< p.pa << std::endl;
  Pair *hp = new Pair(23,42);
  std::cout <<"Oxe: "<< hp->pa << std::endl;
  delete hp;
  
  std::cout << "If this message is printed,"
    << " at least the program hasn't crashed yet!\n"
    << "But you may want to print other diagnostic messages too." << std::endl;
  return 0;
}