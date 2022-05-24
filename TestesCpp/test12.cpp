
#include <iostream>
#include <assert.h>
#include <vector>
#include <array>

struct SecondPiolaKirchhoffStressTensor
{
private:
    double _Tensor[3];

public:
    double &_Sxx = _Tensor[0];
    double &_Syy = _Tensor[1];
    double &_Sxy = _Tensor[2];

    
    SecondPiolaKirchhoffStressTensor(double Sxx, double Syy, double Sxy)
    :_Tensor{Sxx,Syy,Sxy}
    {
        std::cout<<"chamou0" << std::endl;
    }

    template <size_t n>
    SecondPiolaKirchhoffStressTensor(double (&tensor)[n])
    :SecondPiolaKirchhoffStressTensor{tensor[0],tensor[1],tensor[2]}
    {
        std::cout<<"chamou1" << std::endl;
        assert(sizeof(double) * n == 24); //double has size of 8 bits n must be 3 to 2D tensor states
    }

    SecondPiolaKirchhoffStressTensor(std::vector<double> tensor)
    {
        std::cout<<"chamou2" << std::endl;
        assert(tensor.size() == 3);
        for (size_t i = 0; i < 3; ++i)
        {
            _Tensor[i] = tensor[i];
        }
    }
    
    SecondPiolaKirchhoffStressTensor()
    :SecondPiolaKirchhoffStressTensor{0.0,0.0,0.0}
    {std::cout<<"chamou3" << std::endl;}

    double& operator[] (int index)
    {
        assert(index >= 0 && index < 3);
    
        return _Tensor[index];
    }

    const double& operator[] (int index) const // for const objects: can only be used for access
    {
        assert(index >= 0 && index < 3);
        
        return _Tensor[index];
    }
};

struct aStress : public SecondPiolaKirchhoffStressTensor
{
    aStress(double Sxx, double Syy, double Sxy)
    :SecondPiolaKirchhoffStressTensor{Sxx,Syy,Sxy}
    {}
};

class ContinuumPoint2D
{
private:
    SecondPiolaKirchhoffStressTensor _secondPiolaKirchhoffStress;
    //damage scalar variables, and plastic variables can be included too

public:
};

int main()
{
    double a[3]{1.0,2.0,3.0};
    std::vector<double> b{27,37,42};
    SecondPiolaKirchhoffStressTensor SPKT(13,5,7);
    SecondPiolaKirchhoffStressTensor SPKT2(a);
    SecondPiolaKirchhoffStressTensor SPKT3(b);
    SecondPiolaKirchhoffStressTensor SPKT4{101,102,103};
    
    SecondPiolaKirchhoffStressTensor SPKT5;

    aStress test(1.0,1.1,2.8);

    std::cout << SPKT._Sxx << std::endl;
    std::cout << SPKT[0] << std::endl;
    std::cout << &(SPKT._Sxx) << std::endl;
    std::cout << &(SPKT[0]) << std::endl;
    std::cout << &(SPKT._Syy) << std::endl;
    std::cout << SPKT2._Sxx << std::endl;
    std::cout << SPKT2[0] << std::endl;
    std::cout << &(SPKT2._Sxx) << std::endl;
    std::cout << &(SPKT2[0]) << std::endl;
    std::cout << &(SPKT2._Syy) << std::endl;
    SPKT2._Sxx = 0.1;
    std::cout << SPKT2._Sxx << std::endl;
    SPKT2[0] = 0.3;
    std::cout << SPKT2._Sxx << std::endl;
    SPKT2[0] = SPKT2._Sxx;
    std::cout << SPKT2._Sxx << std::endl;
    SPKT2._Sxx = SPKT2[0];
    std::cout << SPKT2._Sxx << std::endl;

    std::cout << b.size() << std::endl;

    std::cout << test[0] << std::endl;
    std::cout << test[1] << std::endl;
    std::cout << test[2] << std::endl;
}