#include<iostream>
int main()
{
    std::cout << (1-2)%2 << std::endl;
    std::cout << (2-2)%2 << std::endl;
    std::cout << (3-2)%2 << std::endl;

    std::cout << (((-1)%2))+1 << std::endl;
    std::cout << (((-2)%2))+1 << std::endl;
    std::cout << (((-3)%2))+1 << std::endl;
    
    int dim = 1;
    for(int row = 0; row<3; ++row)
    {
        for(int column = 0; column<3; ++column)
        {
            std::cout << row << "," << column << ": " << row + ((column)-1+dim)*(!(row == column)) << std::endl;
        }
    }

    std::cout << "-------------------------------------" << std::endl;
    dim = 2;
    for(int row = 0; row<3; ++row)
    {
        for(int column = 0; column<3; ++column)
        {
            std::cout << row << "," << column << ": " << row + ((column)-1+dim)*(!(row == column)) << std::endl;
        }
    }

    std::cout << "-------------------------------------" << std::endl;
    dim = 3;
    for(int row = 0; row<3; ++row)
    {
        for(int column = 0; column<3; ++column)
        {
            int n1 = row + ((column)-1+dim)*(!(row == column));
            std::cout << row << "," << column << ": " << n1 << std::endl;
        }
    }

    dim = 3;
    for(int realDim = 1; realDim < 4; ++realDim)
    {
        std::cout << "--------------" << realDim <<"--------------------" << std::endl;
        for(int row = 0; row<3; ++row)
        {
            for(int column = 0; column<3; ++column)
            {
                int n1 = row + ((column)-1+dim)*(!(row == column));
                int n2 = (((-realDim)%2))+1;
                int n3 = (n1==2)-(n1==3);
                std::cout << row << "," << column << ": " << n1+n2*n3 << std::endl;
            }
        }
        
    }
}