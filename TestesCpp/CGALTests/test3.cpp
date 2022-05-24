#pragma once
// Constructing an arrangement with curve history.
// #include <CGAL/Cartesian.h>
// #include <CGAL/Exact_rational.h>
#include <CGAL/Point_2.h>
#include <CGAL/Segment_2.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
// #include <CGAL/Arr_segment_traits_2.h>
#include <CGAL/Arr_linear_traits_2.h>
// #include <CGAL/Arrangement_on_surface_with_history_2.h>
#include <CGAL/Arrangement_with_history_2.h>
#include <CGAL/Arr_simple_point_location.h>
// #include "point_location_utils.h"
#include <CGAL/Triangulation_2.h>
#include <CGAL/draw_triangulation_2.h>
typedef CGAL::Exact_predicates_exact_constructions_kernel                       Kernel;
typedef CGAL::Exact_predicates_tag                                              Itag;

typedef CGAL::Arr_segment_traits_2<Kernel>                Traits_2;
typedef Kernel::Point_2                                   Point_2;
typedef Kernel::Segment_2                               Segment_2;
typedef CGAL::Arrangement_with_history_2<Traits_2>        Arr_with_hist_2;
// typedef Arr_with_hist_2::Curve_handle                     Curve_handle;
// typedef CGAL::Arr_simple_point_location<Arr_with_hist_2>  Point_location;
typedef CGAL::Constrained_Delaunay_triangulation_2<Kernel, CGAL::Default, Itag>     CDT2;


int main()
{
  Arr_with_hist_2   arr;
  // Insert s1, s2 and s3 incrementally:
  Segment_2 s1(Point_2(0, 3), Point_2(4, 3));
  insert(arr, s1);
  Segment_2 s2(Point_2(3, 2), Point_2(3, 5));
  insert(arr, s2);
  Segment_2 s3(Point_2(2, 3), Point_2(5, 3));
  insert(arr, s3);
  // Insert three additional segments aggregately:
  Segment_2 segs[3];
  segs[0] = Segment_2(Point_2(2, 6), Point_2(7, 1));
  segs[1] = Segment_2(Point_2(0, 0), Point_2(2, 6));
  segs[2] = Segment_2(Point_2(3, 4), Point_2(6, 4));
  insert(arr, segs, segs + 3);
  // Print out the curves and the number of edges each one induces.
//   Arr_with_hist_2::Curve_iterator            cit;
//   std::cout << "The arrangement contains "
//             << arr.number_of_curves() << " curves:" << std::endl;
//   for (cit = arr.curves_begin(); cit != arr.curves_end(); ++cit)
//     std::cout << "Curve [" << *cit << "] induces "
//               << arr.number_of_induced_edges(cit) << " edges." << std::endl;
//   // Print the arrangement edges, along with the list of curves that
//   // induce each edge.

  CDT2 CDT;
  for (auto it = arr.edges_begin(); it != arr.edges_end(); ++it) {
        CDT.insert(it->source()->point(), it->target()->point());
    } 
    CGAL::draw(CDT);
    return EXIT_SUCCESS;  
}