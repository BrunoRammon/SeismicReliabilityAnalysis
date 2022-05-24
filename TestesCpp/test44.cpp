#include<iostream>
#include<vector>
#include <chrono>
#include <iomanip>
#include<omp.h>
using namespace std;
/********************************************************************
Sample OpenMP program which at stage 1 has 4 threads and at stage 2 has 2 threads
**********************************************************/
int main()
{
  // #pragma omp parallel  num_threads(4) //*create 4 threads and region inside it will be executed by all   threads . */
  // {
  //   #pragma omp critical//allow one thread at a time to access below statement
  //   cout<<" Thread Id  in OpenMP stage 1=  "<<omp_get_thread_num()<< endl;
  // }  //here all thread get merged into one thread id

  // cout<<"I am alone"<<endl;

  // #pragma omp parallel num_threads(2)//create two threads
  // {
  //   cout<<" Thread Id  in OpenMP stage 2=  "<<omp_get_thread_num()<<  endl;;
  // }

  std::cout << 4%2 << std::endl;
  unsigned long long n = 500000000;
  std::vector<unsigned long long>vec(n,0.0);

  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  {
    for(unsigned long long i = 0; i < n; ++i)
    {
      if(i%2 == 0)
      {
        vec[i] = i;
      }
      else
      {
        vec[i]=i+1;
      }
    }
  }  
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();end = std::chrono::steady_clock::now();
  
  std::cout << "TOTAL TIME: " << std::setprecision(6) << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()/1.0e+6 << std::fixed << " sec." << std::endl << std::endl;

  begin = std::chrono::steady_clock::now();
  
  #pragma omp parallel for 
    for(unsigned long long i = 0; i < n; ++i)
    {
      if(i%2 == 0)
      {
        vec[i] = i;
      }
      else
      {
        vec[i]=i+1;
      }
    }
  end = std::chrono::steady_clock::now();

  std::cout << "TOTAL TIME: " << std::setprecision(6) << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()/1.0e+6 << std::fixed << " sec." << std::endl << std::endl;


  begin = std::chrono::steady_clock::now();
  int count = 0;
  #pragma omp parallel
  { 
    #pragma omp for
    for(unsigned long long i = 0; i < n; ++i)
    {
      if(i%2 == 0)
      {
        vec[i] = i;
      }
      else
      {
        vec[i]=i+1;
      }
      #pragma omp critical
      ++count;
    }
  }
  // }
  end = std::chrono::steady_clock::now();

  std::cout << "TOTAL TIME: " << std::setprecision(6) << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()/1.0e+6 << std::fixed << " sec." << std::endl << std::endl;
  
  begin = std::chrono::steady_clock::now();
  {
    for(unsigned long long i = 0; i < n; ++i)
    {
      if(i%2 == 0)
      {
        vec[i] = i;
      }
      else
      {
        vec[i]=i+1;
      }
    }
  }  
  end = std::chrono::steady_clock::now();

  std::cout << "TOTAL TIME: " << std::setprecision(6) << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()/1.0e+6 << std::fixed << " sec." << std::endl << std::endl;

}