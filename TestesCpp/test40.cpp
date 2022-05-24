
#include<vector>
#include<iostream>

void func(std::vector<int>&vec)
{
    std::cout << vec.size() << std::endl;
    std::cout << vec.capacity() << std::endl;
    vec.reserve(6);
    std::cout << vec.size() << std::endl;
    std::cout << vec.capacity() << std::endl;
    for(int i = 0; i < 6; ++i)
    {
        vec.emplace_back(i);
    }
    std::cout << vec.size() << std::endl;
    std::cout << vec.capacity() << std::endl;
}
int main()
{
    std::vector<int>vec;
    std::cout << vec.size() << std::endl;
    std::cout << vec.capacity() << std::endl;
    func(vec);
    std::cout << vec.size() << std::endl;
    std::cout << vec.capacity() << std::endl;
}   
