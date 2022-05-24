#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<std::vector<double>>>vecs(2,std::vector<std::vector<double>>({{}}));
    std::cout << vecs[0][0].size() << std::endl;
}