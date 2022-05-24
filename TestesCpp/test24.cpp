#include<iostream>

struct Tensor
{
private:
    int _dimension{2};
    double** _Tensor{};
public:
    Tensor();
    void initialize();
};
Tensor::Tensor(){}
//initilization operator
void Tensor::initialize()
{
    std::cout << "_Tensor[0]" << std::endl;
    std::cout << _Tensor[0] << std::endl;
    _Tensor = new double*[_dimension]{};
    for(int i = 0; i < _dimension; ++i)
    {   
        _Tensor[i] = new double[_dimension]{};
    }
}
int main()
{
    Tensor T;
    T.initialize();
    // std::cout << _Tensor[0] << std::endl;
    // std::cout << _Tensor[1] << std::endl;
    // std::cout << _Tensor[0][0] << std::endl;
    // std::cout << _Tensor[0][1] << std::endl;
    // std::cout << _Tensor[1][0] << std::endl;
    // std::cout << _Tensor[1][1] << std::endl;
}