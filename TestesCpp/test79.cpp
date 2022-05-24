#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>


struct Coordinates
{
    double x;
    double y;
};
struct Element
{
    // std::vector<nodeIndex>connectivity;
    std::vector<const Coordinates*> const connectivity;

};
void importMeshToBuild(std::string inputFileName, std::vector<Coordinates>& nodes,std::vector<Element>& elements)
{
    std::ifstream myfile; 
    myfile.open(inputFileName);
    std::vector<std::string> str;
    if ( myfile.is_open() ) 
    {
        while ( myfile ) 
        {
            std::string myline;
            std::getline (myfile, myline);
            str.push_back(myline);
        }
    };
    
    int nNodes = std::stoi(str[0]);
    
    nodes.reserve(nNodes);
    for(int i = 1; i <= nNodes; ++i)
    {
        std::string strCoords = str[i];
        std::istringstream is( strCoords );
        std::vector<double> coordinates(2);
        double n;
        int j = 0;
        while( is >> n ) { 
            // std::cout << n << std::endl;
            coordinates[j] = n;
            // std::cout << coordinates[j] << std::endl;
            ++j;
        }
        nodes.emplace_back(Coordinates{coordinates[0],coordinates[1]});
    }
    // std::cout << std::cin.get();
    // for(Coordinates coord : nodes)
    // {
    //     std::cout << coord.x << ", " << coord.y << std::endl;
    // }
    int nElements = std::stoi(str[nNodes+1]);
    // std::cout << nElements << std::endl;
    elements.reserve(nElements);
    for(int i = nNodes+2; i <= nNodes+1+nElements; ++i)
    {
        std::string strCoords = str[i];
        std::istringstream is( strCoords );
        std::vector<int> connec(3);
        int n;
        int j = 0;
        while( is >> n ) { 
            connec[j] = n;
            ++j;
        }
        
        elements.emplace_back(Element{{&nodes[connec[0]], &nodes[connec[1]], &nodes[connec[2]]}});
    }
}

int main()
{
    std::vector<Coordinates>nodes1;
    std::vector<Element>elements1;
    importMeshToBuild("input.txt",nodes1,elements1);

    for(Coordinates coord : nodes1)
    {
        std::cout << coord.x << ", " << coord.y << std::endl;
    }
    for(Element elem : elements1)
    {
        for(const Coordinates* coord : elem.connectivity)
        {
            std::cout << coord->x << "," << coord->y << "; ";
        }
        std::cout << std::endl;
    }
}
