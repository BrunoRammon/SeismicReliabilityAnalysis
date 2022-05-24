#include <iostream>
#include <assert.h>

#include<vector>

enum class Dimension
{
    UNIDIMENSIONAL = 1,
    BIDIMENSIONAL = 2,
    TRIDIMENSIONAL = 3
};
enum class SymmetricDimension
{
    ZERO = 0,
    UNIDIMENSIONAL = 1,
    BIDIMENSIONAL = 3,
    TRIDIMENSIONAL = 6,
};

class Tensor
{
private:
    static SymmetricDimension dimensionToLenght(Dimension dim)
    {
        switch(dim)
        {
            // case Dimension::ZERO: return SymmetricDimension::ZERO;
            case Dimension::UNIDIMENSIONAL: return SymmetricDimension::UNIDIMENSIONAL;
            case Dimension::BIDIMENSIONAL: return SymmetricDimension::BIDIMENSIONAL;
            case Dimension::TRIDIMENSIONAL: return SymmetricDimension::TRIDIMENSIONAL;
        }
    }

public:
    Dimension _dimension;
    SymmetricDimension _lenght{SymmetricDimension::ZERO};
    double* _Tensor{};
    Tensor() = default;
    Tensor(Dimension dim)
    :_dimension{ dim },_lenght{dimensionToLenght(dim)}
    {        
        _Tensor = new double[_lenght]{};
    }
    const double& operator()(int row, int column) const // can only be used for access
    {
        int dim = static_cast<int>(_dimension);
        assert(row >= dim || column >= dim);
        if (row == column) return _Tensor[row];
        else return _Tensor[(column+row)-1+dim]; // only valid up to three-dimensional tensors
    }
    double& operator()(int row, int column)// can only be used for access
    {
        int dim = static_cast<int>(_dimension);
        assert(row < dim || column < dim);
        if (row == column) return _Tensor[row];
        else return _Tensor[(column+row)-1+dim]; // only valid up to three-dimensional tensors
    }
};

class matrix
{
public: 
    double** _Tensor{};
    matrix()
    {
         _Tensor = new double*[3];
        for(int i = 0; i < 3; ++i)
        {
            _Tensor[i] = new double[3]{};
        }
    }
    const double* const operator[] (int index) const // for const objects: can only be used for access
    {
        assert(index >= 0 && index < 3);
        
        return *(_Tensor+index);
    }
};

int main()
{
    Tensor a(Dimension::BIDIMENSIONAL);
    // std::cout << a._Tensor[0] << std::endl;
    // std::cout << a._Tensor[1] << std::endl;
    // std::cout << a._Tensor[2] << std::endl;
    // std::cout << a._Tensor[3] << std::endl;
    // std::cout << static_cast<int>(a._lenght) << std::endl;
    std::cout << static_cast<int>(a._dimension) << std::endl;
    std::cout << a(1,0) << std::endl;
    a(1,0) =2;
    std::cout << a(1,0) << std::endl;
    // Tensor b;
    // std::cout << static_cast<int>(b._lenght) << std::endl;
    // std::cout << static_cast<int>(b._dimension) << std::endl;

    matrix m;
    std::cout << m[0][7] << std::endl;
    std::cout << 2*!(2==2) << std::endl;
}