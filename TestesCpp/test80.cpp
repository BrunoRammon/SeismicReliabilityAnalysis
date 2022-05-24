#include <vector>
#include <iostream>
#include <algorithm>
int main()
{
    std::vector<double> vec{-3.5,1.0,10.9,-3.49,8.7,7.6,-5.8,9.5};
    for(double n : vec)
    {
        std::cout << n << ", ";
    }
    std::cout << std::endl;
    std::sort(vec.begin(),vec.end());
    for(double n : vec)
    {
        std::cout << n << ", ";
    }
    std::cout << std::endl;

}