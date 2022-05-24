#include<vector>
#include <string>
#include <iostream>
#include <sstream>

int main() {
    std::string s = "100.1 123.8 42.7";
    std::istringstream is( s );
    double n;
    std::vector<double>vec(3);
    
    int i = 0;
    while( is >> n ) {  
        vec[i] = n;
        ++i;
    }
    for(double num : vec)
    {
        std::cout << num << std::endl;
    }
}