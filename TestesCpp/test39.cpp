
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nodes;
    nodes.reserve(6);
    std::cout << nodes.size() << std::endl;
    std::cout << nodes.capacity() << std::endl;

    for(int i = 0; i<3; ++i)
    {
        nodes.emplace_back(i);
    }
    std::cout << nodes.size() << std::endl;
    std::cout << nodes.capacity() << std::endl;
    nodes.resize(nodes.size());
    std::cout << nodes.size() << std::endl;
    std::cout << nodes.capacity() << std::endl;

    for(int node : nodes)
    {
        std::cout << node << std::endl;
    }
}   