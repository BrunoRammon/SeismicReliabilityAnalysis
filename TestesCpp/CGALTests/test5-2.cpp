// #pragma once

#include<vector>
#include<array>
#include<iostream>
#include<cmath>
#include<unordered_map>

#include <sstream>

#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_circular_kernel_2.h>

#include <CGAL/Point_2.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/draw_polygon_2.h>
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

#include <CGAL/Point_3.h>
#include <CGAL/Plane_3.h>
#include <CGAL/Segment_3.h>
#include <CGAL/Surface_mesh.h>

#include <CGAL/Polygon_mesh_processing/triangulate_faces.h>
#include <CGAL/Polygon_mesh_processing/clip.h>
#include <CGAL/Polygon_mesh_processing/repair.h>

#include <CGAL/squared_distance_3.h> 
#include <CGAL/Delaunay_triangulation_3.h>

#include <CGAL/draw_triangulation_2.h>

#include <stdio.h>
#include <omp.h>

typedef CGAL::Exact_predicates_exact_constructions_kernel                       K1;
typedef CGAL::Exact_circular_kernel_2                                           K2;
typedef CGAL::Exact_predicates_tag                                              Itag;
// typedef CGAL::Exact_intersections_tag                                          Itag;

typedef CGAL::Polygon_2<K1>                                                     Polygon2;
typedef CGAL::Arr_linear_traits_2<K1>                                           Traits2;
typedef CGAL::Arr_segment_traits_2<K1>                                          Traits_2;
typedef CGAL::Arrangement_2<Traits2>                                            Arrangement2;
typedef CGAL::Arrangement_with_history_2<Traits2>                               ArrangementWH2;
typedef CGAL::Arrangement_2<Traits_2>                                           Arrangement_2;
typedef CGAL::Arrangement_with_history_2< Traits_2>                             ArrangementWH_2;
typedef CGAL::Delaunay_triangulation_2<K1>                                      Delaunay2;
typedef CGAL::Constrained_Delaunay_triangulation_2<K1, CGAL::Default, Itag>     CDT2;

typedef K1::Point_2                                                             Point2;
typedef CGAL::Polygon_2<K1>                                                      Polygon_2;
typedef K1::Segment_2                                                           Segment2;
typedef Traits_2::Point_2                                                       Point_2;
typedef Traits_2::X_monotone_curve_2                                            Segment_2;
// typedef Traits_2::Curve_2                                                       Segment_2;
typedef K1::Line_2                                                              Line2;
typedef K1::Ray_2                                                               Ray2;
typedef K1::Triangle_2                                                          Triangle2;

typedef K2::Point_2                                                             Point2Circ;
typedef K2::Segment_2                                                           Segment2Circ;
typedef K2::Circle_2                                                            Circle2Circ;
typedef K2::Line_2                                                              Line2Circ;
typedef K2::Line_arc_2                                                          LineArc2Circ;

typedef K1::Point_3                                                             Point3;
typedef K1::Plane_3                                                             Plane3;
typedef K1::Segment_3                                                           Segment3;
typedef CGAL::Surface_mesh<Point3>                                              SurfaceMesh;
typedef CGAL::Delaunay_triangulation_3<K1>                                      Delaunay3;

typedef CGAL::Arr_walk_along_line_point_location<Arrangement2>                  WalkPL;
typedef CGAL::Arr_naive_point_location<Arrangement_2>                           WalkPL_2;
typedef CGAL::Arr_point_location_result<Arrangement2>                           PointLocationResult;
typedef std::pair<Point2, PointLocationResult::Type>                            QueryResult;
typedef CGAL::Triangulation_2<K1>                                               Triangulation2;

typedef Arrangement2::Vertex_handle                                             Vertex_handle;
typedef Arrangement2::Vertex_const_handle                                       Vertex_const_handle;
typedef Arrangement2::Halfedge_handle                                           Halfedge_handle;
typedef Arrangement2::Halfedge_const_handle                                     Halfedge_const_handle;
typedef Arrangement2::Face_handle                                               Face_handle;
typedef Arrangement2::Face_const_handle                                         Face_const_handle;

typedef CGAL::Box_intersection_d::Box_d<double,2>                               Box;
typedef CGAL::Bbox_2                                                            Bbox;


using nodeIndex = int;

struct Coordinates
{
    double x;
    double y;
};
double triangleArea(const Coordinates& p1, const Coordinates& p2, const Coordinates& p3) {         //find area of triangle formed by p1, p2 and p3
   return std::abs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y)+ p3.x*(p1.y-p2.y))/2.0);
}
struct Element
{
    // std::vector<nodeIndex>connectivity;
    std::vector<const Coordinates*> const connectivity;

    
    bool pointLiesInsideElement(double x, double y, bool verbose)
    {
        
        Coordinates coord;
        coord.x = x;
        coord.y = y;

        double areaElem = triangleArea(*connectivity[0],*connectivity[1],*connectivity[2]);
        double area1 = triangleArea(coord,*connectivity[1],*connectivity[2]);
        double area2 = triangleArea(*connectivity[0],coord,*connectivity[2]);
        double area3 = triangleArea(*connectivity[0],*connectivity[1],coord);
        
        if(verbose)
        {
        std::cout << "x: " << coord.x << " y: " << coord.y << std::endl;
        // std::cout << "x: "<< connectivity[0]->x << std::endl;
        // std::cout << "y: "<< connectivity[0]->y << std::endl;
        // std::cout << "x: "<< connectivity[1]->x << std::endl;
        // std::cout << "y: "<< connectivity[1]->y << std::endl;
        // std::cout << "x: "<< connectivity[2]->x << std::endl;
        // std::cout << "x: "<< connectivity[2]->y << std::endl;
        std::cout << "AreaElem: "<< areaElem << std::endl;
        // std::cout << area1 << std::endl;
        // std::cout << area2 << std::endl;
        // std::cout << area3 << std::endl;
        std::cout << "AreaAcc" << area1+area2+area3 << std::endl;
        // if(areaElem == area1 + area2 + area3)
        // {
        //     std::cout << "true" << std::endl;
        // }
        // std::cout << std::cin.get() << std::endl;
        }

        


        return (std::abs(areaElem-(area1 + area2 + area3)) < 10e-4 );
    }
    double area()
    {
        return triangleArea(*connectivity[0],*connectivity[1],*connectivity[2]);
    }
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
        const Coordinates* refCoords = elem.connectivity[0];
        double refMaxCoordX = refCoords->x;
        double refMinCoordX = refCoords->x;
        double refMaxCoordY = refCoords->y;
        double refMinCoordY = refCoords->y;

        for(const Coordinates* coord : elem.connectivity)
        {
            if(coord->x > refMaxCoordX)
            {
                refMaxCoordX = coord->x;
            }
            else
            if(coord->x < refMinCoordX)
            {
                refMinCoordX = coord->x;
            }

            if(coord->y > refMaxCoordY)
            {
                refMaxCoordY = coord->y;
            }
            else
            if(coord->y < refMinCoordY)
            {
                refMinCoordY = coord->y;
            }
        }

        boxes.emplace_back(Bbox(refMinCoordX,refMinCoordY,refMaxCoordX,refMaxCoordY));
        // if(i==9)
        // {
        //     std::cout << refMinCoordX << ", " << refMinCoordY << ", " << refMaxCoordX << ", " << refMaxCoordY << std::endl << std::endl;
        // }
        
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

void exportIntegrationMesh(std::string name, std::vector<Element*> integrationMesh)
{
    // char* file;
    // const char* completePath = __FILE__;
    // while (*completePath) {
    //     if (*completePath++ == '/') {
    //         file = (const_cast<char *>(completePath));
    //     }
    // }
    // std::string sFile = file;
    // sFile = sFile.substr(0, sFile.size()-4);
    // // std::string path = "./examples";
    // // std::string currentPath = path + "/" + sFile;
    // // boost::filesystem::create_directories(currentPath);
    // std::string name = "test5-2.vtu"; 

    std::cout<<"Writing '" << name << "'...\n";
    std::fstream output_file;
    output_file.open(name, std::ios::out);

    if(output_file.is_open())
    {
        std::stringstream codeNodes;
        std::stringstream codeConec;
        std::stringstream CodeElemType;
        std::stringstream codeOffsets;
        codeNodes            << "        " << "<DataArray type=\"Float32\" NumberOfComponents=\"3\" format=\"ascii\">"                         << "\n" << std::fixed << std::setprecision(10);
        codeConec            << "        " << "<DataArray type=\"Int32\" Name=\"connectivity\">"                                                  << std::endl << std::fixed << std::setprecision( 0);
        CodeElemType         << "        " << "<DataArray type=\"Int32\" Name=\"types\">"                                                         << std::endl << std::fixed << std::setprecision( 0);
        codeOffsets          << "        " << "<DataArray type=\"Int32\" Name=\"offsets\">"                                                       << std::endl << std::fixed << std::setprecision( 0);
        int accum = 0;
        int ncells = 0;
        for (Element* elem : integrationMesh)
        {
            for(int i = 0; i < 3; ++i)
            {
                codeNodes << elem->connectivity[i]->x << " " << elem->connectivity[i]->y << " " << 0.0 << " ";
                codeConec << accum << " ";
                ++accum;
            }
            codeOffsets  << accum << " ";
            CodeElemType << 69 << " ";
            ++ncells;
        }
        int npoints = ncells*3;
        codeNodes    << std::endl << "        " << "</DataArray>" << std::endl;
        codeConec    << std::endl << "        " << "</DataArray>" << std::endl;
        codeOffsets  << std::endl << "        " << "</DataArray>" << std::endl;
        CodeElemType << std::endl << "        " << "</DataArray>" << std::endl;

        // VTU file header
        output_file << "<?xml version=\"1.0\"?>" << std::endl
        << "<VTKFile type=\"UnstructuredGrid\">" << std::endl
        << "  " << "<UnstructuredGrid>" << std::endl
        << "    " << "<Piece NumberOfPoints=\""<< npoints << "\" " << "NumberOfCells=\"" << ncells << "\">" << std::endl;

        // POINTS

        output_file << "      " << "<Points>" << std::endl;
        output_file << codeNodes.str();
        output_file << "      " << "</Points>" << std::endl;

        // CONECTIVITY

        output_file << std::fixed << std::setprecision(0);
        output_file << "      " << "<Cells>" << std::endl;
        output_file << codeConec.str();
        output_file << codeOffsets.str();
        output_file << CodeElemType.str();
        output_file << "      " << "</Cells>" << std::endl;

        output_file << "    " << "</Piece>" << std::endl
        << "  " << "</UnstructuredGrid>" << std::endl
        << "</VTKFile>" << std::endl;
    }
    output_file.close();
}

void importMeshToBuild(std::string inputFileName, std::vector<Coordinates>& nodes,std::vector<Element>& elements)
{
    // std::cout << "BreakPoint" << std::cin.get();
    std::ifstream myfile; 
    myfile.open(inputFileName);
    std::vector<std::string> str;
    if ( myfile.is_open() ) 
    {
        while ( myfile ) 
        {
            std::string myline;
            std::getline (myfile, myline);
            // std::cout << myline << std::cin.get();
            str.push_back(myline);
        }
    }
    else
    {
        std::cout << "DeuRuim" << std::cin.get();
    }
    // std::cout << "BreakPoint" << std::cin.get();
    int nNodes = std::stoi(str[0]);
    // std::cout << nNodes << std::endl;
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
    double L = 1.0;
    int den = 20;
    int num = 7;
    double transX = 0.0;
    double transY = 0.2;
    // double transY = L/2 - num *L/den;
    // std::vector<Coordinates>nodes1{
    //     Coordinates{0, 0}, 
    //     Coordinates{L, 0}, 
    //     Coordinates{L, L}, 
    //     Coordinates{0, L}, 
    //     Coordinates{L/2, L/2}
    // };
    // std::vector<Element>elements1{
    //     Element{{&nodes1[0], &nodes1[1], &nodes1[4]}}, 
    //     Element{{&nodes1[1], &nodes1[2], &nodes1[4]}}, 
    //     Element{{&nodes1[2], &nodes1[3], &nodes1[4]}},
    //     Element{{&nodes1[3], &nodes1[0], &nodes1[4]}}
    // };
    std::vector<Coordinates>nodes1;
    std::vector<Element>elements1;
    // importMeshToBuild("input.txt",nodes1,elements1);
    importMeshToBuild("mesh3.txt",nodes1,elements1);

    // for(Coordinates coord : nodes1)
    // {
    //     std::cout << coord.x << ", " << coord.y << std::endl;
    // }
    // for(Element elem : elements1)
    // {
    //     for(const Coordinates* coord : elem.connectivity)
    //     {
    //         std::cout << coord->x << "," << coord->y << "; ";
    //     }
    //     std::cout << std::endl;
    // }
    StructuralProblem problem1(nodes1,elements1);
    // std::cout << std::cin.get();

    // std::vector<Coordinates>nodes2{
    //     Coordinates{0, 0}, 
    //     Coordinates{L, 0}, 
    //     Coordinates{L, L}, 
    //     Coordinates{0, L},
    //     Coordinates{L, L/2+transY},
    //     Coordinates{0, L/2+transY}, 
    //     Coordinates{num * L/den + transX, L/2 + transY}, 
    //     Coordinates{L/2 + transX, num * L/den + transY},
    //     Coordinates{L -  num * L/den + transX, L/2 + transY},
    //     Coordinates{L/2 + transX, L - num * L/den + transY}
    // };
    // std::vector<Element>elements2{
    //     Element{{&nodes2[0],&nodes2[7],&nodes2[6]}}, 
    //     Element{{&nodes2[0],&nodes2[1],&nodes2[7]}}, 
    //     Element{{&nodes2[1],&nodes2[8],&nodes2[7]}}, 
    //     Element{{&nodes2[1],&nodes2[4],&nodes2[8]}}, 
    //     Element{{&nodes2[4],&nodes2[2],&nodes2[8]}}, 
    //     Element{{&nodes2[2],&nodes2[9],&nodes2[8]}},
    //     Element{{&nodes2[2],&nodes2[3],&nodes2[9]}},
    //     Element{{&nodes2[3],&nodes2[6],&nodes2[9]}},
    //     Element{{&nodes2[3],&nodes2[5],&nodes2[6]}},
    //     Element{{&nodes2[5],&nodes2[0],&nodes2[6]}},
    //     Element{{&nodes2[6],&nodes2[7],&nodes2[8]}},
    //     Element{{&nodes2[6],&nodes2[8],&nodes2[9]}}
    // };
    std::vector<Coordinates>nodes2;
    std::vector<Element>elements2;
    importMeshToBuild("mesh4.txt",nodes2,elements2);
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

    // int i = 0;
    // for(std::vector<int> elems2: elem1ToElem2)
    // {
    //     std::cout << "Element1: " << i << std::endl;
    //     ++i;
    //     for(int elem2Number :elems2)
    //     {
    //         std::cout << elem2Number << ", ";
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << std::endl;
    // int iElem1 = 0;
    // int elemNumber;
    // for(Element elem : elements1)
    // {
    //     // if(elem.pointLiesInsideElement(-64.4918,-118.956,false))
    //     if(elem.pointLiesInsideElement(-32.7215,89.5792,false))
    //     {
    //         std::cout << iElem1 << std::endl;
    //         elemNumber = iElem1;
    //     }
    //     ++iElem1;
    // }
    // std::cout << std::cin.get();
    std::vector<Element*> integrationMesh;
    #pragma omp parallel /*if(_parallelOptimization)*/
    {
        std::vector<Element*> integrationMesh_private;
        #pragma omp for nowait 
        for(int i = 0; i < elem1ToElem2.size(); ++i)
        {
            // std::cout << i << ": " << std::endl;
            auto it = elem1ToElem2.begin()+i;
            Element elem1 = elements1[i];
            
            // int nNodes = elem1ToElem2[i].size()*3;
            // std::vector<double>coordX(nNodes);
            // std::vector<double>coordY(nNodes);
            // int id = 0;
            // for(int elemNumber2 : elem1ToElem2[i])
            // {
            //     Element elem2 = elements2[elemNumber2];
            //     for(int j = 0; j < elem2.connectivity.size(); ++j)
            //     {
            //         coordX[id] = elem2.connectivity[j]->x;
            //         coordY[id] = elem2.connectivity[j]->y;
            //         ++id;
            //     }
                
            // }
            // std::sort(coordX.begin(),coordX.end());
            // std::sort(coordY.begin(),coordY.end());
            

            Arrangement2 arr;
            WalkPL walkPL(arr);
            // Point2 p1; convertCoords2SS(coordX[0], coordY[0]) >> p1;
            // Point2 p2; convertCoords2SS(coordX[coordX.size()-1], coordY[0]) >> p2;
            // Point2 p3; convertCoords2SS(coordX[coordX.size()-1], coordY[coordY.size()-1]) >> p3;
            // Point2 p4; convertCoords2SS(coordX[0], coordY[coordY.size()-1]) >> p4;
            // Segment2 seg1 (p1, p2);
            // CGAL::insert(arr, seg1, walkPL);
            // Segment2 seg2 (p2, p3);
            // CGAL::insert(arr, seg2, walkPL);
            // Segment2 seg3 (p3, p4);
            // CGAL::insert(arr, seg3, walkPL);
            // Segment2 seg4 (p4, p1);
            // CGAL::insert(arr, seg4, walkPL);
        
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
                    Point2 pi; convertCoords2SS((*iteri)->x, (*iteri)->y) >> pi;
                    Point2 pf; convertCoords2SS((*iterf)->x, (*iterf)->y) >> pf;
                    Segment2 seg (pi, pf);
                    CGAL::insert(arr, seg, walkPL);
                }
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
                Point2 pi; convertCoords2SS((*iteri)->x, (*iteri)->y) >> pi;
                Point2 pf; convertCoords2SS((*iterf)->x, (*iterf)->y) >> pf;
                Segment2 seg (pi, pf);
                CGAL::insert(arr, seg, walkPL);
            }

            CDT2  CDT;
            for (auto it = arr.edges_begin(); it != arr.edges_end(); ++it) 
            {
                CDT.insert(it->source()->point(), it->target()->point());
            }
            // if(i == elemNumber)
            // {
            //     for(int elemNumber2 : *it)
            //     {
            //         std::cout << elemNumber2 << ", ";
            //     }
            //     std::cout << std::endl;
            //     std::vector<Element*> localIntegrationMesh;
            //     int countFF = 0;
            //     // for (auto facet = CDT.all_faces_begin (); facet < CDT.all_faces_end(); ++facet)
            //     for (auto facet : CDT.finite_face_handles()) 
            //     {
            //         std::array<std::array<double,3>,3> nodesCoord{ \
            //         {{CGAL::to_double(facet->vertex(0)->point().x()), CGAL::to_double(facet->vertex(0)->point().y()), 0.0},
            //         {CGAL::to_double(facet->vertex(1)->point().x()), CGAL::to_double(facet->vertex(1)->point().y()), 0.0}, 
            //         {CGAL::to_double(facet->vertex(2)->point().x()), CGAL::to_double(facet->vertex(2)->point().y()), 0.0}}}; 
            //         double p1x = nodesCoord[0][0];
            //         double p1y = nodesCoord[0][1];
            //         double p2x = nodesCoord[1][0];
            //         double p2y = nodesCoord[1][1];
            //         double p3x = nodesCoord[2][0];
            //         double p3y = nodesCoord[2][1];
            //         Coordinates* n1 = new Coordinates();
            //         Coordinates* n2 = new Coordinates();
            //         Coordinates* n3 = new Coordinates();
            //         n1->x = p1x; 
            //         n1->y = p1y;
            //         n2->x = p2x; 
            //         n2->y = p2y;
            //         n3->x = p3x; 
            //         n3->y = p3y;
            //         Element* elem = new Element{{n1,n2,n3}};
            //         localIntegrationMesh.push_back(elem);
            //         ++countFF;
                    
            //     }
            //     std::cout << "Number of Faces: " << CDT.number_of_faces() << std::endl;
            //     std::cout << "Number of Finite Faces: " << countFF << std::endl;
            //     exportIntegrationMesh("localMesh"+std::to_string(i)+".vtu",localIntegrationMesh);
            //     CGAL::draw(CDT);
            //     // std::cout << std::cin.get();
            // }
            
        


            int numbOfSubElement = CDT.number_of_faces();
            std::vector<bool>vecContainTwoElements(numbOfSubElement,false);
            std::vector<Element>vecElems1;
            vecElems1.reserve(numbOfSubElement);
            std::vector<Element>vecElems2;
            vecElems2.reserve(numbOfSubElement);
            int iFacet = 0;
            // Arrangement2 arrgmt;
            // WalkPL walkPLg(arrgmt);
            // integrationMesh.reserve(numbOfSubElement);
            std::vector<Element*> localIntegrationMesh; 
            for (auto facet : CDT.finite_face_handles()) 
            {
                std::array<std::array<double,3>,3> nodesCoord{ \
                    {{CGAL::to_double(facet->vertex(0)->point().x()), CGAL::to_double(facet->vertex(0)->point().y()), 0.0},
                    {CGAL::to_double(facet->vertex(1)->point().x()), CGAL::to_double(facet->vertex(1)->point().y()), 0.0}, 
                    {CGAL::to_double(facet->vertex(2)->point().x()), CGAL::to_double(facet->vertex(2)->point().y()), 0.0}}}; // It is always a triangulation

                std::array<double,3> subElemMidCoord{(nodesCoord[0][0]+nodesCoord[1][0]+nodesCoord[2][0])/3,(nodesCoord[0][1]+nodesCoord[1][1]+nodesCoord[2][1])/3,0.0}; //calculate center of subelement
                
                double areaSubElem = triangleArea(Coordinates{nodesCoord[0][0],nodesCoord[0][1]},Coordinates{nodesCoord[1][0],nodesCoord[1][1]},Coordinates{nodesCoord[2][0],nodesCoord[2][1]});
                double areaElem1 = elem1.area();

                int countElem2 = 0;
                // std::vector<Element> keepElements; 
                // std::vector<int> keepElementsNumber;
                
                if(/*areaSubElem/areaElem1>0.005 &&*/ elem1.pointLiesInsideElement(subElemMidCoord[0], subElemMidCoord[1], false))
                {
                    // std::cout <<"Elem1 Entrou" << std::endl;
                    vecElems1.emplace_back(elem1);
                    for(int elemNumber2 : *it)
                    { 
                        Element elem2 = elements2[elemNumber2];
                        if(elem2.pointLiesInsideElement(subElemMidCoord[0], subElemMidCoord[1], false))
                        {
                            // std::cout <<"Elem2 Entrou" << std::endl;
                            vecElems2.emplace_back(elem2);
                            vecContainTwoElements[iFacet] = true;
                            // Polygon_2 plg;
                            // plg.push_back(Point2(CGAL::to_double(facet->vertex(0)->point().x()), CGAL::to_double(facet->vertex(0)->point().y())));
                            // plg.push_back(Point2(CGAL::to_double(facet->vertex(1)->point().x()), CGAL::to_double(facet->vertex(1)->point().y())));
                            // plg.push_back(Point2(CGAL::to_double(facet->vertex(2)->point().x()), CGAL::to_double(facet->vertex(2)->point().y())));
                            // CGAL::draw(plg);
                            double p1x = nodesCoord[0][0];
                            double p1y = nodesCoord[0][1];
                            double p2x = nodesCoord[1][0];
                            double p2y = nodesCoord[1][1];
                            double p3x = nodesCoord[2][0];
                            double p3y = nodesCoord[2][1];
                            Coordinates* n1 = new Coordinates();
                            Coordinates* n2 = new Coordinates();
                            Coordinates* n3 = new Coordinates();
                            n1->x = p1x; 
                            n1->y = p1y;
                            n2->x = p2x; 
                            n2->y = p2y;
                            n3->x = p3x; 
                            n3->y = p3y;
                            Element* elem = new Element{{n1,n2,n3}};
                            integrationMesh_private.push_back(elem);
                            // keepElements.push_back(elem2);
                            // keepElementsNumber.push_back(elemNumber2);
                            // if(i == elemNumber)
                            // {
                            //     localIntegrationMesh.push_back(elem);
                            //     // std::cout << elemNumber2 << std::endl;
                            // }
                            ++countElem2;
                            break;
                        }
                    }
                }            
                // if(countElem2 > 1)
                // {
                //     std::cout  << "Tá errado isso aí, hein!" << std::endl;
                //     std::cout  << "Subelem: " << subElemMidCoord[0] << "," << subElemMidCoord[1] << std::endl;
                //     std::cout << nodesCoord[0][0] << "," << nodesCoord[0][1] << "; " 
                //     << nodesCoord[1][0] << "," << nodesCoord[1][1] << "; "
                //     << nodesCoord[2][0] << "," << nodesCoord[2][1] << std::endl;
                //     std::cout << "Elem1 " << i << ": ";
                //     for(const Coordinates* const coords : elem1.connectivity)
                //     {
                //         std::cout << coords->x << "," << coords->y << "; ";
                //     }
                //     std::cout << std::endl;
                //     int iEl = 0;
                //     for(Element elem : keepElements)
                //     {
                //         std::cout << keepElementsNumber[iEl] << std::endl;
                //         for(const Coordinates* const coords : elem.connectivity)
                //         {
                //             std::cout << coords->x << "," << coords->y << "; ";
                //         }
                //         std::cout << std::endl;
                //         ++iEl;
                //     }
                //     std::cout << std::cin.get();
                //     // system("read");
                // }
                
                // if (vecContainTwoElements[iFacet])
                // {
                //     std::cout << "true2" << std::endl;
                //     Element elem1 = vecElems1[iFacet];
                //     Element elem2 = vecElems2[iFacet];
                    

                //     for(auto iter = elem1.connectivity.begin(); iter != elem1.connectivity.end(); ++iter)
                //     // for(nodeIndex nodeId : elem2.connectivity)
                //     {
                //         auto iteri = iter;
                //         auto iterf = iter + 1;
                //         if(iterf == elem1.connectivity.end())
                //         {
                //             iterf = elem1.connectivity.begin();
                //         }
                //         Point2 pi; convertCoords2SS((*iteri)->x, (*iteri)->y) >> pi;
                //         Point2 pf; convertCoords2SS((*iterf)->x, (*iterf)->y) >> pf;
                //         Segment2 seg (pi, pf);
                //         CGAL::insert(arrgmt, seg, walkPLg);
                //     }
                    
                //     for(auto iter = elem2.connectivity.begin(); iter != elem2.connectivity.end(); ++iter)
                //     // for(nodeIndex nodeId : elem2.connectivity)
                //     {
                //         auto iteri = iter;
                //         auto iterf = iter + 1;
                //         if(iterf == elem2.connectivity.end())
                //         {
                //             iterf = elem2.connectivity.begin();
                //         }
                //         Point2 pi; convertCoords2SS((*iteri)->x, (*iteri)->y) >> pi;
                //         Point2 pf; convertCoords2SS((*iterf)->x, (*iterf)->y) >> pf;
                //         Segment2 seg (pi, pf);
                //         CGAL::insert(arrgmt, seg, walkPLg);
                //     }                
                // }
                ++iFacet;
            }
            // if(i == elemNumber)
            // {
            //     exportIntegrationMesh("localMesh"+std::to_string(i)+"(2).vtu",localIntegrationMesh);
            // }

            // CDT2  CDTriang;
            // for (auto it = arrgmt.edges_begin(); it != arrgmt.edges_end(); ++it) 
            // {
            //     CDTriang.insert(it->source()->point(), it->target()->point());
            // }
            // CGAL::draw(CDTriang);
            // std::cout << std::cin.get();
        }
        #pragma omp critical
        integrationMesh.insert(integrationMesh.end(), integrationMesh_private.begin(), integrationMesh_private.end());
    }
    exportIntegrationMesh("test5-2.vtu",integrationMesh);

}




