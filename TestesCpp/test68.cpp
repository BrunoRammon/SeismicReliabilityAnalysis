#include<iostream>
#include<vector>
#include <chrono>
#include <iomanip>
#include<omp.h>

int main()
{   
    int n = 100000000;
    std::vector<int> vecit(n,0);
    std::vector<int> vec;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    #pragma omp parallel for 
    for(unsigned long long i = 0; i < n; ++i)
    {
        #pragma omp critical
        vec.push_back(0);
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();end = std::chrono::steady_clock::now();
    std::cout << "TOTAL TIME: " << std::setprecision(6) << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()/1.0e+6 << std::fixed << " sec." << std::endl << std::endl;

    begin = std::chrono::steady_clock::now();
    std::vector<int> vec2;
    vec2.reserve(n);
    #pragma omp parallel
    {
        std::vector<int> vec_private;
        vec_private.reserve(n/omp_get_num_threads());
        #pragma omp for nowait //fill vec_private in parallel
        for(auto it = vecit.begin(); it<vecit.end(); ++it) {
            vec_private.emplace_back(0);
        }
        #pragma omp critical
        vec2.insert(vec2.end(), vec_private.begin(), vec_private.end());
    }
    end = std::chrono::steady_clock::now();end = std::chrono::steady_clock::now();
    std::cout << "TOTAL TIME: " << std::setprecision(6) << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()/1.0e+6 << std::fixed << " sec." << std::endl << std::endl;

    

    begin = std::chrono::steady_clock::now();
    std::vector<int> vec3;
    vec2.reserve(n);
    for(unsigned long long i = 0; i < n; ++i)
    {
        vec3.emplace_back(0);
    }
    end = std::chrono::steady_clock::now();end = std::chrono::steady_clock::now();
    std::cout << "TOTAL TIME: " << std::setprecision(6) << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()/1.0e+6 << std::fixed << " sec." << std::endl << std::endl;
}