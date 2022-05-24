#include <vector>
#include <iostream>

void func(std::vector<double>a)
{
    std::cout << a[0] << std::endl;
}
int main()
{
    func({1.0,2.0});
}