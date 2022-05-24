
#include <typeinfo>
#include <iostream>
#include <array>
int main()
{
    // int a[2][2]={{1,2},{3,4}};
    int ***mats = new int**[1];

    
    for (size_t i = 0; i < 2; i++)
    {
        mats[i] = new int*[2];

        for (size_t j = 0; j < 2; j++)
        {
            mats[i][j] = new int[2];
            for (size_t k = 0; k < 2; k++)
            {
                mats[i][j][k] = i+j+k;
            }

        }

    }

    // int* &cmat = mats[0];
    // std::cout << typeid(mats[0]).name() << std::endl;
    // //std::cout << typeid(cmat).name() << std::endl;
    // std::cout << cmat[0][0] << std::endl;
    // std::cout << cmat[1][1] << std::endl;

}