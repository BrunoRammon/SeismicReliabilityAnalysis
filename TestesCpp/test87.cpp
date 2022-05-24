#include <iostream>
#include <vector>

int main()
{
    int _mp = 3;
    int _mcorr = _mp;
    int _m = 8;
    int j = _mp % _m;
    // std::cout << j << std::endl;
    for(int i=0; i<_mcorr; i++)
    {
        j = (j + _m - 1) % _m;
        std::cout << j << std::endl;
    }
    std::cout << std::endl;
    for(int i=_mcorr-1; i>=0; --i)
    {
        std::cout << i << std::endl;
    }

    std::cout << std::endl;
    for(int i=0; i<_mcorr; i++)
    {
        std::cout << j << std::endl;
        j = (j + 1) % _m;
    }

    std::cout << std::endl;
    for(int i=0; i<_mcorr; i++)
    {
        std::cout << i << std::endl;
    }
}