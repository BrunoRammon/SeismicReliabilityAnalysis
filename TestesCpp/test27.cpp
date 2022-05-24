
#include <iostream>
#include <vector>

class test
{
private:   
    std::vector<std::vector<double>> _test;
public:
    test()
    :_test(std::vector<std::vector<double>>(1,std::vector<double>(1,0.0)))
    {}
    void print()
    {
        std::cout << _test[0][0] << std::endl;
        std::cout << _test[0][1] << std::endl;
        std::cout << _test[0].size() << std::endl;
    }
};

int main()
{
    test a;

    a.print();

    std::vector<std::vector<double>>vec = std::vector<std::vector<double>>(1,std::vector<double>(1,0.0));
    std::cout << vec[0][0] << std::endl;
    std::cout << vec[0][1] << std::endl;
    std::cout << vec[0][2] << std::endl;
    std::cout << vec[0].size() << std::endl;
    std::cout << vec[0].capacity() << std::endl;
    std::cout << vec.capacity() << std::endl;

}