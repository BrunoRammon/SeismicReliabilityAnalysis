#include<vector>
#include<array>
#include<iostream>
#include<cmath>
#include<unordered_map>
#include <CGAL/box_intersection_d.h>
#include <CGAL/Bbox_2.h>

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_circular_kernel_2.h>

#include <CGAL/Point_2.h>
#include <CGAL/Segment_2.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/Arr_segment_traits_2.h>
#include <CGAL/Arrangement_2.h>
#include <CGAL/Arrangement_with_history_2.h>
#include <CGAL/Arr_linear_traits_2.h>
#include <CGAL/Arr_walk_along_line_point_location.h>
#include <CGAL/Arr_batched_point_location.h>
#include <CGAL/Arr_naive_point_location.h>
#include <CGAL/Arr_non_caching_segment_basic_traits_2.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Circle_2.h>
#include <CGAL/box_intersection_d.h>
#include <CGAL/Bbox_2.h>

#include <CGAL/Constrained_Delaunay_triangulation_2.h>

#include <CGAL/draw_triangulation_2.h>

typedef CGAL::Exact_predicates_exact_constructions_kernel                       K1;
typedef CGAL::Exact_predicates_tag                                              Itag;

typedef CGAL::Arr_linear_traits_2<K1>                                           Traits2;
typedef CGAL::Arrangement_2<Traits2>                                            Arrangement2;
typedef CGAL::Constrained_Delaunay_triangulation_2<K1, CGAL::Default, Itag>     CDT2;

typedef K1::Point_2                                                             Point2;
typedef K1::Segment_2                                                           Segment2;

typedef CGAL::Arr_walk_along_line_point_location<Arrangement2>                  WalkPL;

typedef CGAL::Box_intersection_d::Box_d<double,2>                               Box;
typedef CGAL::Bbox_2                                                            Bbox;

using nodeIndex = int;

struct Coordinates
{
    double x;
    double y;
};
float triangleArea(Coordinates p1, Coordinates p2, Coordinates p3) {         //find area of triangle formed by p1, p2 and p3
   return std::abs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y)+ p3.x*(p1.y-p2.y))/2.0);
}
struct Element
{
    std::vector<nodeIndex>connectivity;

    
    // bool pointLiesInsideElement(double x, double y)
    // {
    //     double areaElem = triangleArea(connectivity[0],connectivity[1],connectivity[2]);
    //     double area1 = triangleArea(Coordinates(x,y),connectivity[1],connectivity[2]);
    //     double area2 = triangleArea(connectivity[0],Coordinates(x,y),connectivity[2]);
    //     double area3 = triangleArea(connectivity[0],connectivity[1],Coordinates(x,y));
    //     return (areaElem == area1 + area2 + area3);
    // }
};

struct StructuralProblem
{
    std::vector<Coordinates>nodes;
    std::vector<Element>elements;
    StructuralProblem(std::vector<Coordinates>&nods,std::vector<Element>elems)
        : nodes(nods),elements(elems)
    {}
};


struct ConstructMappingBBox
{
    std::unordered_map<int,int>* _mappingBoxToElem1;
    std::unordered_map<int,int>* _mappingBoxToElem2;
    std::vector<std::vector<int>>* _elem1ToElem2;
    
    ConstructMappingBBox(std::unordered_map<int,int>& mapping1,std::unordered_map<int,int>& mapping2,std::vector<std::vector<int>>& elem1ToElem2)
    : _mappingBoxToElem1(&mapping1),_mappingBoxToElem2(&mapping2),_elem1ToElem2(&elem1ToElem2)
    {};
    
    void operator()(const Box& a, const Box& b) const
    {
        int element1 = _mappingBoxToElem1->at(a.id());
        int element2 = _mappingBoxToElem2->at(b.id());
        _elem1ToElem2->at(element1).push_back(element2);
    }
};

std::vector<Box> createBboxes(StructuralProblem problem)
{
    std::vector<Box> boxes;
    boxes.reserve(problem.elements.size());
    int i = 0;
    for(Element elem : problem.elements)
    {   
        Coordinates refCoords = problem.nodes[elem.connectivity[0]];
        double refMaxCoordX = refCoords.x;
        double refMinCoordX = refCoords.x;
        double refMaxCoordY = refCoords.y;
        double refMinCoordY = refCoords.y;

        for(nodeIndex nodeId : elem.connectivity)
        {
            if(problem.nodes[nodeId].x > refMaxCoordX)
            {
                refMaxCoordX = problem.nodes[nodeId].x;
            }
            else
            if(problem.nodes[nodeId].x < refMinCoordX)
            {
                refMinCoordX = problem.nodes[nodeId].x;
            }

            if(problem.nodes[nodeId].y > refMaxCoordY)
            {
                refMaxCoordY = problem.nodes[nodeId].y;
            }
            else
            if(problem.nodes[nodeId].y < refMinCoordY)
            {
                refMinCoordY = problem.nodes[nodeId].y;
            }
        }

        boxes.emplace_back(Bbox(refMinCoordX,refMinCoordY,refMaxCoordX,refMaxCoordY));
        if(i==9)
        {
            std::cout << refMinCoordX << ", " << refMinCoordY << ", " << refMaxCoordX << ", " << refMaxCoordY << std::endl << std::endl;
        }
        
        ++i;
        
    }

    return boxes;
}

std::stringstream convertCoords2SS(const double& x, const double& y)
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(13) << x << " " << y;
    
    return ss;
}

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
    std::vector<Element>elements1{
        Element{{0, 1, 4}}, 
        Element{{1, 2, 4}}, 
        Element{{2, 3, 4}},
        Element{{3, 0, 4}}
    };
    StructuralProblem problem1(nodes1,elements1);

    std::vector<Coordinates>nodes2{
        Coordinates{0, 0}, 
        Coordinates{L, 0}, 
        Coordinates{L, L}, 
        Coordinates{0, L},
        Coordinates{L, L/2+transY},
        Coordinates{0, L/2+transY}, 
        Coordinates{num * L/den + transX, L/2 + transY}, 
        Coordinates{L/2 + transX, num * L/den + transY},
        Coordinates{L -  num * L/den + transX, L/2 + transY},
        Coordinates{L/2 + transX, L - num * L/den + transY}
    };
    std::vector<Element>elements2{
        Element{{0,7,6}}, 
        Element{{0,1,7}}, 
        Element{{1,8,7}}, 
        Element{{1,4,8}}, 
        Element{{4,2,8}}, 
        Element{{2,9,8}},
        Element{{2,3,9}},
        Element{{3,6,9}},
        Element{{3,5,6}},
        Element{{5,0,6}},
        Element{{6,7,8}},
        Element{{6,8,9}}
    };
    StructuralProblem problem2(nodes2,elements2);

    std::vector<Box> boxes1 = createBboxes(problem1);
    std::vector<Box> boxes2 = createBboxes(problem2);

    std::unordered_map<int,int> mappingBoxToElem1;
    int iElem = 0;
    for(Box box : boxes1)
    {
        mappingBoxToElem1[box.id()] = iElem;
        ++iElem;
    }

    std::unordered_map<int,int> mappingBoxToElem2;
    iElem = 0;
    for(Box box : boxes2)
    {
        mappingBoxToElem2[box.id()] = iElem;
        ++iElem;
    }

    std::vector<std::vector<int>> elem1ToElem2(elements1.size(),std::vector<int>{});
    CGAL::box_intersection_d(boxes1.begin(), boxes1.end(), boxes2.begin(), boxes2.end(), ConstructMappingBBox(mappingBoxToElem1,mappingBoxToElem2,elem1ToElem2),std::ptrdiff_t(1),CGAL::Box_intersection_d::HALF_OPEN);

    int i = 0;
    for(std::vector<int> elems2: elem1ToElem2)
    {
        std::cout << "Element1: " << i << std::endl;
        ++i;
        for(int elem2Number :elems2)
        {
            std::cout << elem2Number << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    for(int i = 0; i < elem1ToElem2.size(); ++i)
    {
        auto it = elem1ToElem2.begin()+i;
        Element elem1 = elements1[i];
        Arrangement2 arr;
        WalkPL walkPL(arr);
        for(int elemNumber2 : *it)
        {
            Element elem2 = elements2[elemNumber2];
            for(auto iter = elem2.connectivity.begin(); iter != elem2.connectivity.end(); ++iter)
            // for(nodeIndex nodeId : elem2.connectivity)
            {
                auto iteri = iter;
                auto iterf = iter + 1;
                if(iterf == elem2.connectivity.end())
                {
                    iterf = elem2.connectivity.begin();
                }
                Point2 pi; convertCoords2SS(problem2.nodes[*iteri].x, problem2.nodes[*iteri].y) >> pi;
                Point2 pf; convertCoords2SS(problem2.nodes[*iterf].x, problem2.nodes[*iterf].y) >> pf;
                Segment2 seg (pi, pf);
                CGAL::insert(arr, seg, walkPL);
            }
            std::cout << elemNumber2 << std::endl;
        }
        for(auto iter = elem1.connectivity.begin(); iter != elem1.connectivity.end(); ++iter)
        // for(nodeIndex nodeId : elem2.connectivity)
        {
            auto iteri = iter;
            auto iterf = iter + 1;
            if(iterf == elem1.connectivity.end())
            {
                iterf = elem1.connectivity.begin();
            }
            Point2 pi; convertCoords2SS(problem2.nodes[*iteri].x, problem2.nodes[*iteri].y) >> pi;
            Point2 pf; convertCoords2SS(problem2.nodes[*iterf].x, problem2.nodes[*iterf].y) >> pf;
            Segment2 seg (pi, pf);
            CGAL::insert(arr, seg, walkPL);
        }

        CDT2  CDT;
        for (auto it = arr.edges_begin(); it != arr.edges_end(); ++it) 
        {
            CDT.insert(it->source()->point(), it->target()->point());
        }

        // int numbOfSubElement = CDT.number_of_faces();
        // std::vector<bool>vecContainTwoElements(numbOfSubElement,false);
        // std::vector<Element>vecElems1;
        // vecElems1.reserve(numbOfSubElement);
        // std::vector<Element>vecElems2;
        // vecElems2.reserve(numbOfSubElement);
        // int iFacet = 0;
        // Arrangement2 arrgmt;
        // WalkPL walkPLg(arrgmt);
        // for (auto facet = CDT.finite_faces_begin(); facet < CDT.finite_faces_end(); ++facet)
        // {
        //     std::array<std::array<double,3>,3> nodesCoord{ \
        //         {{CGAL::to_double(facet->vertex(0)->point().x()), CGAL::to_double(facet->vertex(0)->point().y()), 0.0},
        //         {CGAL::to_double(facet->vertex(1)->point().x()), CGAL::to_double(facet->vertex(1)->point().y()), 0.0}, 
        //         {CGAL::to_double(facet->vertex(2)->point().x()), CGAL::to_double(facet->vertex(2)->point().y()), 0.0}}}; // It is always a triangulation

        //     std::array<double,3> subElemMidCoord{(nodesCoord[0][0]+nodesCoord[1][0]+nodesCoord[2][0])/3,(nodesCoord[0][1]+nodesCoord[1][1]+nodesCoord[2][1])/3,0.0}; //calculate center of subelement

        //     if(elem1.pointLiesInsideElement(subElemMidCoord[0], subElemMidCoord[1]))
        //     {
        //         vecElems1.emplace_back(elem1);
        //         for(int elemNumber2 : *it)
        //         { 
        //             Element elem2 = elements2[elemNumber2];
        //             if(elem2.pointLiesInsideElement(subElemMidCoord[0], subElemMidCoord[1]))
        //             {
        //                 vecElems2.emplace_back(elem2);
        //                 vecContainTwoElements[iFacet] = true;
        //                 break;
        //             }
        //         }
        //     }

            

        //     if (vecContainTwoElements[iFacet])
        //     {
        //         Element elem1 = vecElems1[iFacet];
        //         Element elem2 = vecElems2[iFacet];
                

        //         for(auto iter = elem1.connectivity.begin(); iter != elem1.connectivity.end(); ++iter)
        //         // for(nodeIndex nodeId : elem2.connectivity)
        //         {
        //             auto iteri = iter;
        //             auto iterf = iter + 1;
        //             if(iterf == elem1.connectivity.end())
        //             {
        //                 iterf = elem1.connectivity.begin();
        //             }
        //             Point2 pi; convertCoords2SS(problem2.nodes[*iteri].x, problem2.nodes[*iteri].y) >> pi;
        //             Point2 pf; convertCoords2SS(problem2.nodes[*iterf].x, problem2.nodes[*iterf].y) >> pf;
        //             Segment2 seg (pi, pf);
        //             CGAL::insert(arrgmt, seg, walkPLg);
        //         }
                
        //         for(auto iter = elem2.connectivity.begin(); iter != elem2.connectivity.end(); ++iter)
        //         // for(nodeIndex nodeId : elem2.connectivity)
        //         {
        //             auto iteri = iter;
        //             auto iterf = iter + 1;
        //             if(iterf == elem2.connectivity.end())
        //             {
        //                 iterf = elem2.connectivity.begin();
        //             }
        //             Point2 pi; convertCoords2SS(problem2.nodes[*iteri].x, problem2.nodes[*iteri].y) >> pi;
        //             Point2 pf; convertCoords2SS(problem2.nodes[*iterf].x, problem2.nodes[*iterf].y) >> pf;
        //             Segment2 seg (pi, pf);
        //             CGAL::insert(arrgmt, seg, walkPLg);
        //         }                
        //     }
        //     ++iFacet;
        // }

        // CDT2  CDTriang;
        // for (auto it = arrgmt.edges_begin(); it != arrgmt.edges_end(); ++it) 
        // {
        //     CDT.insert(it->source()->point(), it->target()->point());
        // }
        // CGAL::draw(CDTriang);
        // std::cout << std::cin.get();
    }

}


