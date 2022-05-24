#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_circular_kernel_2.h>

#include <CGAL/Point_2.h>
#include <CGAL/Segment_2.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/Arr_segment_traits_2.h>
#include <CGAL/Arrangement_2.h>
#include <CGAL/Arr_linear_traits_2.h>
#include <CGAL/Arr_walk_along_line_point_location.h>
#include <CGAL/Arr_batched_point_location.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Circle_2.h>

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

#include <iostream>
#include<cmath>

#include <vector>
#include <array>
#include<iterator>

typedef CGAL::Exact_predicates_exact_constructions_kernel                       K1;
typedef CGAL::Exact_circular_kernel_2                                           K2;
typedef CGAL::Exact_predicates_tag                                              Itag;
// typedef CGAL::Exact_intersections_tag                                          Itag;

typedef CGAL::Polygon_2<K1>                                                     Polygon2;
typedef CGAL::Arr_linear_traits_2<K1>                                           Traits2;
typedef CGAL::Arrangement_2<Traits2>                                            Arrangement2;
typedef CGAL::Delaunay_triangulation_2<K1>                                      Delaunay2;
typedef CGAL::Constrained_Delaunay_triangulation_2<K1, CGAL::Default, Itag>     CDT2;

typedef K1::Point_2                                                             Point2;
typedef K1::Segment_2                                                           Segment2;
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
typedef CGAL::Arr_point_location_result<Arrangement2>                           PointLocationResult;
typedef std::pair<Point2, PointLocationResult::Type>                            QueryResult;
typedef CGAL::Triangulation_2<K1>                                               Triangulation2;

typedef Arrangement2::Vertex_handle                                             Vertex_handle;
typedef Arrangement2::Vertex_const_handle                                       Vertex_const_handle;
typedef Arrangement2::Halfedge_handle                                           Halfedge_handle;
typedef Arrangement2::Halfedge_const_handle                                     Halfedge_const_handle;
typedef Arrangement2::Face_handle                                               Face_handle;
typedef Arrangement2::Face_const_handle                                         Face_const_handle;

const double pi = std::acos(-1);
int main( )
{
    Arrangement2 arr;                   
    WalkPL walkPL(arr);
    //construct two non-intersecting nested polygons
    double ri = 4.0;
    double re = 5.0;
    Point2 p11(ri*std::cos(0*pi),ri*std::sin(0*pi)); 
    Point2 p21(ri*std::cos(pi/4),ri*std::sin(pi/4));
    Point2 p31(ri*std::cos(pi/2),ri*std::sin(pi/2));
    Point2 p41(re*std::cos(0*pi),re*std::sin(0*pi));
    Point2 p51(re*std::cos(pi/4),re*std::sin(pi/4));
    Point2 p61(re*std::cos(pi/2),re*std::sin(pi/2));
    
    Segment2 seg1(p11,p41);
    CGAL::insert(arr, seg1, walkPL);
    Segment2 seg2(p41,p51);
    CGAL::insert(arr, seg2, walkPL);
    Segment2 seg3(p51,p21);
    CGAL::insert(arr, seg3, walkPL);
    Segment2 seg4(p21,p11);
    CGAL::insert(arr, seg4, walkPL);

    Segment2 seg5(p21,p51);
    CGAL::insert(arr, seg5, walkPL);
    Segment2 seg6(p51,p61);
    CGAL::insert(arr, seg6, walkPL);
    Segment2 seg7(p61,p31);
    CGAL::insert(arr, seg7, walkPL);
    Segment2 seg8(p31,p21);
    CGAL::insert(arr, seg8, walkPL);

    CDT2 CDT;

    for (auto it = arr.edges_begin(); it != arr.edges_end(); ++it) {
        CDT.insert(it->source()->point(), it->target()->point());
    }
    int numbOfSubElement = CDT.number_of_faces();

    std::vector<std::array<std::array<double,3>,3>> vec;
    vec.reserve(numbOfSubElement);
    std::cout << "Oxente" << std::endl;
    int i = 0;
    for (auto facet = CDT.finite_faces_begin(); facet < CDT.finite_faces_end(); ++facet)
    {
        std::array<std::array<double,3>,3> nodesCoord{\
            {{CGAL::to_double(facet->vertex(0)->point().x()), CGAL::to_double(facet->vertex(0)->point().y()), 0.0},
             {CGAL::to_double(facet->vertex(1)->point().x()), CGAL::to_double(facet->vertex(1)->point().y()), 0.0}, 
             {CGAL::to_double(facet->vertex(2)->point().x()), CGAL::to_double(facet->vertex(2)->point().y()), 0.0}}};
        vec.emplace_back(nodesCoord);
        ++i;
    }
    
    #pragma omp parallel for
    for(auto it = vec.begin(); it < vec.end(); ++it)
    {
        
        std::cout << "x: " << (*it)[0][0] << ",  y: " << (*it)[0][1] << ",  z: " << (*it)[0][2]<< std::endl;
        std::cout << "x: " << (*it)[1][0] << ",  y: " << (*it)[1][1] << ",  z: " << (*it)[1][2]<< std::endl;
        std::cout << "x: " << (*it)[2][0] << ",  y: " << (*it)[2][1] << ",  z: " << (*it)[2][2]<< std::endl;
    }
    
    
    return 0;
}
