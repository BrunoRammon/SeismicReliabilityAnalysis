
#include<unordered_map>
#include<string>
#include<vector>
#include<iostream>


std::unordered_map<std::string,std::vector<double>>a;
std::vector<double> getFunc(std::string key)
{   
    std::vector<double> n;
    try
    {   
        return a.at(key);
    }
    catch(const std::exception& e)
    {
        // a[key] = std::vector<double>(2, 0.0);
        // n = a.at(key);
        return std::vector<double>{};  
    }

}

int main()
{
    {
        a["a"] = std::vector<double>(2, 1.0);
        a["b"] = std::vector<double>(2, 2.0);
    }
    std::vector<double> n;
    // try
    // {
        
        for(double d : getFunc("a"))
        {
            std::cout << d <<std::endl;
        }
        for(double d : getFunc("b"))
        {
            std::cout << d <<std::endl;
        }
        for(double d : getFunc("c"))
        {
            std::cout << d << std::endl;
        }
        std::cout << getFunc("c").size() << std::endl;

        std::vector<std::vector<int>>a;
        a.reserve(2);
        std::cout << a.size() << std::endl;
        a.emplace_back(std::vector<int>(0,-1));
        a.emplace_back(std::vector<int>(2,-1));
        std::cout << a[0].size() << std::endl;
        std::cout << a[1].size() << std::endl;

        std::vector<std::vector<int>>b;
        b.reserve(3);
        b.emplace_back(std::vector<int>(2,-1));
        b.emplace_back(std::vector<int>(2,-1));
        b.emplace_back(std::vector<int>(2,-1));
        std::cout << b.size() << std::endl;
        b=a;
        std::cout << b.size() << std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     n = std::vector<double>{};
    // }
    // std::cout << n.size() << std::endl;
}