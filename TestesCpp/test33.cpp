#include <iostream>

int main()
{
    int step = 0;
    for(int i = step; i < 10; ++i)
    {
        std::cout << i << std::endl;
        std::cout << step << std::endl;
        ++step;
    }

}