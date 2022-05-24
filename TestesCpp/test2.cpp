#include <iostream>
#include <string>

std::string directory = "./examples/results/MyNLProjectionProblem10/";

int main()
{
    std::cout << directory.substr(19, directory.size()) << std::endl;
}