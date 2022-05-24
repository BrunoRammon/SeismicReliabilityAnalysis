#include <iostream>
#include <vector>

double* func(double a)
{
    double* f = new double[1];
    *f = a;
    return f;
}

std::vector<double> func(double a)
{
    std::vector<double> f = {a};
    
    return f;
}

int main()
{
    double a = 23.79;
    std::vector<double> f1 = func(a);
    double* f2 = func(a);

    std::cout << f1[0] << std::endl;
    std::cout << f2[0] << std::endl;

}