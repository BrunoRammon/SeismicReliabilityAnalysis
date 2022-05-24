#include <iostream>
#include <vector>
#include <stdlib.h>
#include <omp.h>


int main()
{
    int n = 100000;
    std::vector<int> randInt1(10000,0);
    for(int& Int1 : randInt1)
    {
        Int1 = std::rand()%n;
        // std::cout << Int1 << std::endl;
        // std::cin.get();
    }
    std::vector<int> randInt2(20000,0);
    for(int& Int2 : randInt2)
    {
        Int2 = std::rand()%n;
    }

    int count1 = 0;
    int count2 = 0;
    #pragma omp parallel for
    for(int i = 0; i < n; ++i)
    {
        for(int Int1 : randInt1)
        {
            if(Int1 == i)
            {
                ++count1;
                // std::cout << Int1 << std::endl;
                // std::cout << i << std::endl;
                for(int Int2 : randInt2)
                {
                    if(Int2 == i)
                    {
                        ++count2;
                        break;
                    }
                }
                break;
            }
        }
    }
    std::cout << count1 << std::endl;
    std::cout << count2 << std::endl;

    count1 = 0;
    count2 = 0;

    for(int i = 0; i < n; ++i)
    {
        for(int Int1 : randInt1)
        {
            if(Int1 == i)
            {
                ++count1;
                for(int Int2 : randInt2)
                {
                    if(Int2 == i)
                    {
                        ++count2;
                        break;
                    }
                }
                break;
            }
        }
    }

    std::cout << count1 << std::endl;
    std::cout << count2 << std::endl;
}