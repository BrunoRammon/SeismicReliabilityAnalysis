#include <iostream>
#include <vector>

int main()
{
    int dimension = 3;
    for(int k=0; k < dimension; ++k)
    {
        for(int i=0; i < dimension; ++i)
        {
            for(int j=0; j < dimension; ++j)
            {
                
                std::cout << ((i==j)&&(k==dimension-1)) << "   ";
            
            }
            std::cout << std::endl;
        }
    }
}