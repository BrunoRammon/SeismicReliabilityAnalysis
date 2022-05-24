#include <iostream>
#include <vector>

int main()
{
    double *a=new double[5]{1.0,2.0,3.0,4.0,5.0};

    std::vector<double> vecA;
    vecA.insert(vecA.end(),a,a+5);

    for(double elem : vecA)
    {
        std::cout << elem << std::endl;
    }
}