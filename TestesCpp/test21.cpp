#include <iostream>
#include <vector>
void func( std::vector<double> const& a)
{
    std::cout << a[0] << std::endl;
    // a[0] = 3.0;
    std::cout << a[0] << std::endl;
    
}

int main()
{
    std::vector<double> b{1.0,2.0};
    func(b);
}