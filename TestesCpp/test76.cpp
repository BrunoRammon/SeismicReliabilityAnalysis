#include<iostream>
#include<vector>

struct Coordinates
{
    double x;
    double y;
};

int main()
{

    double L = 1.0;
    int den = 20;
    int num = 7;
    double transX = 0.0;
    double transY = 0.2;


    std::vector<Coordinates>nodes1{
        Coordinates{0, 0}, 
        Coordinates{L, 0}, 
        Coordinates{L, L}, 
        Coordinates{0, L}, 
        Coordinates{L/2, L/2}
    };
    std::vector<std::vector<const Coordinates*>> const elements1{
        {&nodes1[0], &nodes1[1], &nodes1[4]}, 
        {&nodes1[1], &nodes1[2], &nodes1[4]}, 
        {&nodes1[2], &nodes1[3], &nodes1[4]},
        {&nodes1[3], &nodes1[0], &nodes1[4]}
    };
}