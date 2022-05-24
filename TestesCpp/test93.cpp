#include <iostream>
#include <string>

std::string option = "T3E";

void (*model)(double L, int nHzDiv , double H,int nVtdiv);
void (*modelStructured)(double L, int nHzDiv , double H,int nVtdiv);
void (*modelNonStructured)(double L, int nHzDiv , double H,int nVtdiv);

std::string meshType;



int main()
{
    if(option == "T3E")
    {
        meshType = "T3";
        model = modelStructured;
    }
    else
    if(option == "T3NE")
    {
        meshType = "T3";
        model = modelNonStructured;
    }
    else
    if(option == "Q4E")
    {
        meshType = "Q4";
        model = modelStructured;
    }
    else
    if(option == "Q4NE")
    {
        meshType = "Q4";
        model = modelNonStructured;
    }
    else
    {
        throw
        std::invalid_argument("Option not available!");
    }
    ;
}