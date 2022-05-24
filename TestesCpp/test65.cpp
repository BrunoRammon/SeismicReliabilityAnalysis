#include<iostream>
#include<vector>
int main()
{
    std::vector<double> a = {1,2,3,4,5,6};
    std::vector<double> b; 
    
    {
        std:: vector<double>c(a.begin(),a.begin()+a.size()-2);
        b = c;
    }

    std::cout << b.size() << std::endl;
}