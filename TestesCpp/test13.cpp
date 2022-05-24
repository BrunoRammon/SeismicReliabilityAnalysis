
#include <iostream>
#include <assert.h>
#include <vector>
#include <array>

struct Tensor
{
private:
    int _length{};
    double* _Tensor{};
public:
    double* _Sxx;
    double* _Syy;
    double* _Szz;
    double* _Sxy;
    double* _Sxz;
    double* _Syz;
    
    Tensor() = default;
    
    Tensor(int length)
    :_length{ length }
    {
        assert(length == 3 || length == 6);
        
        _Tensor = new double[length]{};
    }
    Tensor(int length, double value )
    :_length{ length }
    {
        assert(length == 3 || length == 6);
        
        _Tensor = new double[length]{};
        for (int i = 0; i<length; ++i) _Tensor[i] = value;
    }
    ~Tensor()
    {
        delete[] _Tensor;
        // we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
    }
    Tensor(double Sxx, double Syy, double Sxy)
    :Tensor(3)
    {
        _Tensor[0] = Sxx;
        _Tensor[1] = Syy;
        _Tensor[2] = Sxy;
        _Sxx = &(_Tensor[0]);
        _Syy = &(_Tensor[1]);
        _Sxy = &(_Tensor[2]);
        _Szz = nullptr;
        _Sxz = nullptr;
        _Syz = nullptr;
    }
    Tensor(double Sxx, double Syy, double Szz, double Sxy, double Sxz, double Syz)
    :Tensor(6)
    {
        _Tensor[0] = Sxx;
        _Tensor[1] = Syy;
        _Tensor[2] = Szz;
        _Tensor[3] = Sxy;
        _Tensor[4] = Sxz;
        _Tensor[5] = Syz;
        _Sxx = &(_Tensor[0]);
        _Syy = &(_Tensor[1]);
        _Sxx = &(_Tensor[2]);
        _Sxy = &(_Tensor[3]);
        _Sxz = &(_Tensor[4]);
        _Syz = &(_Tensor[5]);
    }

    double& operator[] (int index)
    {
        assert(index >= 0 && index < _length);
    
        return _Tensor[index];
    }

    const double& operator[] (int index) const // for const objects: can only be used for access
    {
        assert(index >= 0 && index < _length);
        
        return _Tensor[index];
    }

    void operator()(double Sxx, double Syy, double Sxy)
    {
        if (_length != 0)
            return;

        _Tensor = new double[3]{};
        _length = 3;

        _Tensor[0] = Sxx;
        _Tensor[1] = Syy;
        _Tensor[2] = Sxy;
        _Sxx = &(_Tensor[0]);
        _Syy = &(_Tensor[1]);
        _Sxy = &(_Tensor[2]);
        _Szz = nullptr;
        _Sxz = nullptr;
        _Syz = nullptr;
    }

    void operator()(double Sxx, double Syy, double Szz, double Sxy, double Sxz, double Syz)
    {
        if (_length != 0)
            return;

        _Tensor = new double[6]{};
        _length = 6;

        _Tensor[0] = Sxx;
        _Tensor[1] = Syy;
        _Tensor[2] = Szz;
        _Tensor[3] = Sxy;
        _Tensor[4] = Sxz;
        _Tensor[5] = Syz;
        _Sxx = &(_Tensor[0]);
        _Syy = &(_Tensor[1]);
        _Sxx = &(_Tensor[2]);
        _Sxy = &(_Tensor[3]);
        _Sxz = &(_Tensor[4]);
        _Syz = &(_Tensor[5]);
    }


    const int& size() const
    {
        return _length;
    }

    bool tensorIsInitialized() const
    {
        if(size()==3 || size()==6) return true;
        else return false;
    }
};

struct LinearStress : public Tensor
{
    LinearStress()
    :Tensor()
    {}
    LinearStress(double Sxx, double Syy, double Sxy)
    :Tensor{Sxx,Syy,Sxy}
    {}
};
struct NonLinearStress : public Tensor
{
    NonLinearStress()
    :Tensor()
    {}
    NonLinearStress(double Sxx, double Syy, double Sxy)
    :Tensor{Sxx,Syy,Sxy}
    {}
};

struct MaterialPoint
{
public:
    LinearStress _Lstress;
    NonLinearStress _NLstress;
    double _young;
    MaterialPoint()
    {}
    const LinearStress& getLinearStress() const
    {
        return _Lstress;
    }
    const NonLinearStress& getNonLinearStress() const
    {
        return _NLstress;
    }
};

int main()
{
    // Tensor SPKT(13,5,7);
    // std::cout << *(SPKT._Sxx) << std::endl;
    // std::cout << SPKT[0] << std::endl;
    // std::cout << &(SPKT._Sxx) << std::endl;
    // std::cout << &(SPKT[0]) << std::endl;
    MaterialPoint matPt;// (LinearStress{0.1,0.2,0.3});
    MaterialPoint matPt2;
    matPt._Lstress(0.1,0.2,0.3);
    std::cout << matPt._Lstress[0] << std::endl;
    matPt._Lstress[0]+=0.8;
    std::cout << matPt._Lstress[0] << std::endl;
    std::cout <<  matPt.getLinearStress()[2]<< std::endl;
    // double HY[2]{1.05, 1.64};
    // double *hy;
    // hy=HY+1;
    // std::cout << HY[0] << std::endl;
    // std::cout << *hy << std::endl;
    // std::cout << HY << std::endl;
    // std::cout << hy << std::endl;
    // std::cout << HY+1 << std::endl;
    // std::cout << hy << std::endl;

}