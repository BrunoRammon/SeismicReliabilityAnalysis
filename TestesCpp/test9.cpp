#include <iostream>
#include <vector>

int main()
{
    double a = 1.0;
    double b = 2.0;
    double c = 3.0;

    //std::vector<double>{a,b,c};
    std::vector<double>vec{a,b,c};
    std::vector<std::vector<double>>vecvec;
    vecvec.reserve(1);
    vecvec.emplace_back(std::vector<double>{a,b,c});

    std::cout << vecvec.size() << std::endl;
    std::cout << vecvec[0][1] << std::endl;
}