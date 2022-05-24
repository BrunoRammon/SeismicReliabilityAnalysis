#include<unordered_map>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int node = 10;
    switch (node)
    {
        case 0:
            std::cout << 0 << std::endl;
            break;

        case 1:
            std::cout << 1 << std::endl;
            break;
        
        case 2:
            std::cout << 2 << std::endl;
            break;
        
        case 3:
            std::cout << 3 << std::endl;
            break;
        
        default:
            std::cout << "None" << std::endl;
            break;
    }

    std::vector<double> values(2,0.0);

    values = {2.0, 3.0};

    std::cout << values[0] << " " << values[1] << std::endl;

}
