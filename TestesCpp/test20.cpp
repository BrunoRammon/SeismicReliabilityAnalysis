#include <iostream>

double** const func()
{
    double** tensor = new double*[3];
    for (size_t i = 0; i < 3; i++) {
        tensor[i] = new double[3]{};
    }
    tensor[0][0] = 5.0;
    std::cout << tensor[0][0] << std::endl;

    return tensor;
}

int main()
{
    double** const T = func();

    std::cout << T[0][0] << std::endl;
    
    for(int i = 0; i < 3;++i) delete[] T[i];
    delete[]T;

}