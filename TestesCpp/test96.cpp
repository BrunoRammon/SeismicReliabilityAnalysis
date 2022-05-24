#include<unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main()
{
    int i = 1;
    int ci = i;
    int freq = 2;
    for(; i < ci+freq; ++i)
    {
        std::cout << i << std::endl;
        i += freq - 1;
        if (i==1)
        {
            freq = 3;
        }
    }

    std::cout << std::log(2)/std::log(10)<< std::endl;
    std::cout << (int)(std::ceil(1.75))<< std::endl;
}
