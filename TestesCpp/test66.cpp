#include<vector>
#include<iostream>


std::vector<double> _vecA;
const std::vector<double>& getVecA()
{
    return _vecA;
}
std::vector<double> getVecA()
{
    return _vecA;
}
int main()
{
    getVecA();
}