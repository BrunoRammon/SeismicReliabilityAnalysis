
#include<iostream>

bool funcTrue()
{
    std::cout << "Passou funcTrue" << std::endl;
    return true;
}
bool funcFalse()
{
    std::cout << "Passou funcFalse" << std::endl;
    return false;
}
int main()
{
    if(true && funcTrue())
    {
        std::cout << "entrou" << std::endl;
    }
    if(false && funcTrue())
    {
        std::cout << "entrou" << std::endl;
    }
    if(true && funcFalse())
    {
        std::cout << "entrou" << std::endl;
    }
    if(false && funcFalse())
    {
        std::cout << "entrou" << std::endl;
    }

    if(true || funcTrue())
    {
        std::cout << "entrou" << std::endl;
    }
    if(false || funcTrue())
    {
        std::cout << "entrou" << std::endl;
    }
    if(true || funcFalse())
    {
        std::cout << "entrou" << std::endl;
    }
    if(false || funcFalse())
    {
        std::cout << "entrou" << std::endl;
    }
}