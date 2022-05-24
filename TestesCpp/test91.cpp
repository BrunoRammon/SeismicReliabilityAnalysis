#include<stdio.h>
#include<stdlib.h>
#include <iostream>

void func()
{
    // char *ptr = (char*)malloc(10);
    char *ptr = new char[10];
}

int main(void)
{
    std::cout << "primeiro" << std::endl;
    func();
    std::cout << "segundo" << std::endl;

    return 0;
}