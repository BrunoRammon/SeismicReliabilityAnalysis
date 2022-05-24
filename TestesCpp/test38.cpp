
#include <iostream>


// class A
// {
// private:
//     int _var = 3;
// public:
//     const int& getVar() const
//     {
//         return _var;
//     }

//     friend const int& getVar(A* cl);
// };

// const int& getVar(A* cl)
// {
// return cl->_var;
// }

// namespace nmspc;

class A;

namespace nmspc
{
    const int& getVar(A* cl);
}

class A
{
private:
    int _var = 3;
public:
    const int& getVar() const;

    friend const int& nmspc::getVar(A* cl);
};

const int& nmspc::getVar(A* cl)
{
    return cl->_var;
}

// class A
// {
// private:
//     int _var = 3;
// public:
//     const int& getVar() const;

//     friend const int& nmspc::getVar(A* cl);
// };

// const int& A::getVar() const
// {
//     return _var;
// }


int main()
{
    const int& (*getVarFunction)(A*);
    getVarFunction = &nmspc::getVar;

    A* a = new A();
    std::cout << getVarFunction(a) << std::endl;

    std::string w = "b";
    std::string b = "a";
    // if (w=="a",b="a")
    // {
    //     std::cout << "oxente" << std::endl;
    // }
}