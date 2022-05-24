#include <iostream>
#include <functional>

struct stcFunction
{
    int _a;
    int _b;
    static int sum(int a, int b, void* ctx);

    int sumNonStatic(int a, int b);
};

struct problem
{
    stcFunction func;
};



int stcFunction::sum(int a, int b, void* ctx)
{
    problem* var = (problem*) ctx;
    var->func._a = a;
    var->func._b = b;
    return var->func.sumNonStatic(var->func._a,var->func._b);
}

int stcFunction::sumNonStatic(int a, int b)
{
    return a+b;
}


int Function(int(*function)(int,int),int a,int b)
{
    return function(a,b);
}

int Function(int(*function)(int,int,void*),int a,int b,void* ctx)
{
    return function(a,b,ctx);
}

int sum(int a, int b)
{
    return a+b;
}
int main()
{
    int a = 1;
    int b = 2;
    std::cout << Function(sum,a,b) << std::endl;
    stcFunction sum2;
    std::cout << Function(stcFunction::sum,a,b,(void*)(&sum2)) << std::endl;
}