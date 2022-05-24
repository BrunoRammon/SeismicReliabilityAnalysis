#include <CGAL/box_intersection_d.h>
#include <CGAL/Bbox_2.h>
#include <iostream>
#include <vector>
#include <unordered_map>
typedef CGAL::Box_intersection_d::Box_d<double,2> Box;
typedef CGAL::Bbox_2                              Bbox;
                                                     // 9 boxes of a grid

std::vector<Box> boxes = { Bbox( 0,0,1,1), Bbox( 1,0,2,1), Bbox( 2,0,3,1), // low
Bbox( 0,1,1,2), Bbox( 1,1,2,2), Bbox( 2,1,3,2), // middle
Bbox( 0,2,1,3), Bbox( 1,2,2,3), Bbox( 2,2,3,3)};// upper


namespace functions
{
    std::unordered_map<int, std::vector<int>>mapping;

    void callback( const Box& a, const Box& b ) {
        mapping.at(a.id()).push_back(b.id());
        // std::cout << "box " << a.id() << " intersects box " << b.id() << std::endl;
    }
};

std::vector<Box> createBoxes()
{
    std::vector<Box> boxes = { Bbox( 0,0,1,1), Bbox( 1,0,2,1), Bbox( 2,0,3,1), // low
                    Bbox( 0,1,1,2), Bbox( 1,1,2,2), Bbox( 2,1,3,2), // middle
                    Bbox( 0,2,1,3), Bbox( 1,2,2,3), Bbox( 2,2,3,3)};// upper
    return boxes;
}
// 2 selected boxes as query; center and upper right
std::vector<Box> createQuery()
{
    std::vector<Box> query = { Bbox( 1,1,2,2), Bbox( 2,2,3,3)};
    return query;
}

class BBox
{
public:

    struct Report
    {
        std::unordered_map<int,std::vector<int>>* _mapping;
        
        Report(std::unordered_map<int,std::vector<int>>& mapping)
            : _mapping(&mapping)
        {}

        void operator()(const Box& a, const Box& b) const
        {
            _mapping->at(a.id()).push_back(b.id());
        }

    };
    std::vector<Box> createBoxes()
    {
        std::vector<Box> boxes = { Bbox( 0,0,1,1), Bbox( 1,0,2,1), Bbox( 2,0,3,1), // low
                        Bbox( 0,1,1,2), Bbox( 1,1,2,2), Bbox( 2,1,3,2), // middle
                        Bbox( 0,2,1,3), Bbox( 1,2,2,3), Bbox( 2,2,3,3)};// upper
        return boxes;
    }
    // 2 selected boxes as query; center and upper right
    std::vector<Box> createQuery()
    {
        std::vector<Box> query = { Bbox( 1,1,2,2), Bbox( 2,2,3,3)};
        return query;
    }
};
int main()
{
    std::vector<Box> a = createBoxes();
    std::vector<Box> b = createQuery();
    
    
    
    for(Box elem : a)
    {
       functions::mapping[elem.id()] = std::vector<int>{};
    }

    CGAL::box_intersection_d( a.begin(), a.end(), b.begin(), b.end(), functions::callback);


    std::cout << std::endl;
    std::cout << std::endl;
    for(auto& pair : functions::mapping)
    {
        std::cout << pair.first << ": "; 
        for(int num : pair.second)
        {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }

    std::unordered_map<int, std::vector<int>>mapping2;
    int i = 0;
    for(Box elem : a)
    {
        mapping2[elem.id()] = std::vector<int>{i};
        ++i;
    }

    CGAL::box_intersection_d( a.begin(), a.end(), b.begin(), b.end(), BBox::Report(mapping2));

    std::cout << std::endl;
    std::cout << std::endl;
    for(auto& pair : mapping2)
    {
        std::cout << "Box- "<< pair.first << " Element- " << *(pair.second.begin()) <<": ";
        for(int num : std::vector<int>(pair.second.begin()+1,pair.second.end()))
        {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}