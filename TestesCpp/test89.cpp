#include <iostream>


void print(const char value[])
{
    std::cout << value << std::endl;
}
int main()
{
    int m=20;
    std::string s = std::to_string(m);
    char const *pchar = s.c_str();
    print(pchar);
    
}