#include<iostream>
#include<vector>

class Node
{
private: 
    int _a;
    double _c;
public:

    int geta(){return _a;}
    void seta(int a){ _a = a;}

    double getc(){return _c;}
    void setc(double c){_c=c;}
};

Node* func(){return nullptr;}

std::vector<Node*> vecfunc(){}

int main()
{
    std::cout << "Passou" << std::endl;
    Node* a = func();
    std::cout << "Passou" << std::endl;
    if(a!=nullptr)
    {
        std::cout << "Passou" << std::endl;
        int g = a->geta();
        std::cout << "Passou" << std::endl;
        std::cout << g << std::endl;
        std::cout << "Passou" << std::endl;
    }

    std::cout << "Passou2" << std::endl;
    std::vector<Node*> bs = vecfunc();
    std::cout << "Passou2" << std::endl;
    std::cout << bs.size() << std::endl;
    for(Node* b : bs)
    {
        std::cout << "Passou2" << std::endl;
        if(b!=nullptr)
        {
            std::cout << "Passou2" << std::endl;
            int h = b->geta();
            std::cout << "Passou2" << std::endl;
            std::cout << h << std::endl;
            std::cout << "Passou2" << std::endl;
        }
    }
}