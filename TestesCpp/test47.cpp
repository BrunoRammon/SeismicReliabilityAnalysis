#include<vector>
#include<iostream>

int main()
{
    int** a = new int*[3];

    std::vector<int> b{0,1,2};

    for (int i = 0; i < 3; ++i)
    {
        a[i] = new int[b[i]];
    }

    std::cout << a[0][0] << std::endl;

    int* c = new int[0];
    std::cout << c[0] << std::endl;
}