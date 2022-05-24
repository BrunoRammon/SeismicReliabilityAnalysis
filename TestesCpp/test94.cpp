#include<unordered_map>
#include <iostream>
#include <string>

int main()
{
    std::unordered_map<int, double> _currentSizeNodes;

    {
        _currentSizeNodes[0] = 0.0;
        _currentSizeNodes[1] = 0.0;
        _currentSizeNodes[2] = 0.0;
    }

    std::cout << _currentSizeNodes.at(1) << std::endl;

}
