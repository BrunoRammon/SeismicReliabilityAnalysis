#include <vector>
#include <iostream>


int main()
{
    std::vector<double> as;

    // as.push_back(1);
    
    for(double a : as)
    {
        std::cout << a << std::endl;
    }
}