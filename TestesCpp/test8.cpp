#include <iostream>

double** func()
{
    double** kl =  new double*[2];
    for(size_t i=0; i<2; ++i)
    {
        kl[i] = new double[2];
        for(size_t j=0; j<2; ++j)
        {
            kl[i][j] = i+j;
        }
    }
    
    return kl;
}

int main()
{   
    double a = 2.0;
    double* b = &a;
    double** c = &b;
    double** const &  d = func();
}