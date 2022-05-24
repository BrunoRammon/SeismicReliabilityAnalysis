#include<iostream>
#include<vector>
#include <chrono>
#include <iomanip>
#include<omp.h>
#include<unordered_map>


int main()
{
    std::unordered_map<int,double> map;
    std::vector<double> vec;
    for(int i = 0; i < 1000;++i )
    {
        map[i] = static_cast<double>(i);
        vec.push_back(static_cast<double>(i));
    }

    #pragma omp parallel for 
    for(auto it = vec.begin(); it != vec.end();++it)
    {
        std::cout << *it <<std::endl;
    }

    #pragma omp parallel for 
    for(auto it = map.begin(); it != map.end();++it)
    {
        // auto it = map.begin()+i;
        std::cout << it->second <<std::endl;
    }
}