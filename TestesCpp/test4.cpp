#include<iostream>
#include<vector>

int main()
{
    std::vector<std::vector<double>>a{{{1,2,3}}};
    std::cout<<a.back().at(0)<<std::endl;
    std::cout<<a.back().at(1)<<std::endl;
    std::cout<<a.back().at(2)<<std::endl;
    
}