#include <iostream>

enum class Dimension
{
    UNIDIMENSIONAL = 1,
    BIDIMENSIONAL = 2,
    TRIDIMENSIONAL = 3
};
enum class SymmetricDimension
{
    UNIDIMENSIONAL = 1,
    BIDIMENSIONAL = 3,
    TRIDIMENSIONAL = 6
};


int main()
{
    std::cout << static_cast<int>(Dimension::BIDIMENSIONAL) << std::endl;
    std::cout << static_cast<int>(SymmetricDimension::BIDIMENSIONAL) << std::endl;
    std::cout << static_cast<int>(static_cast<SymmetricDimension>(Dimension::TRIDIMENSIONAL)) << std::endl;

    double** _Tensor = new double*[3];
    for(int i = 0; i < 3; ++i)
    {
        _Tensor[i] = new double[3]{};
    }

    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            std::cout << _Tensor[i][j] << "   ";
        }
        std::cout << std::endl;
    }

    std::cout << sizeof(_Tensor[0]) << std::endl;


}