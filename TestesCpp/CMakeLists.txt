# Created by the script cgal_create_CMakeLists
# This is the CMake script for compiling a set of CGAL applications.

cmake_minimum_required(VERSION 3.1...3.15)

project( TestesCpp )


# CGAL and its components
find_package( CGAL QUIET COMPONENTS Qt5 )

if ( NOT CGAL_FOUND )

  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()  

endif()


# Boost and its components
find_package( Boost REQUIRED )

if ( NOT Boost_FOUND )

  message(STATUS "This project requires the Boost library, and will not be compiled.")

  return()  

endif()

# include for local directory

# include for local package


# Creating entries for all C++ files with "main" routine
# ##########################################################


create_single_source_cgal_program( "test10.cpp" )

create_single_source_cgal_program( "test11.cpp" )

create_single_source_cgal_program( "test12.cpp" )

create_single_source_cgal_program( "test13.cpp" )

create_single_source_cgal_program( "test14.cpp" )

create_single_source_cgal_program( "test15.cpp" )


create_single_source_cgal_program( "test17.cpp" )

create_single_source_cgal_program( "test18.cpp" )

create_single_source_cgal_program( "test19.cpp" )

create_single_source_cgal_program( "test1.cpp" )

create_single_source_cgal_program( "test20.cpp" )

create_single_source_cgal_program( "test21.cpp" )

create_single_source_cgal_program( "test22.cpp" )

create_single_source_cgal_program( "test23.cpp" )

create_single_source_cgal_program( "test24.cpp" )

create_single_source_cgal_program( "test25.cpp" )

create_single_source_cgal_program( "test26.cpp" )

create_single_source_cgal_program( "test27.cpp" )

create_single_source_cgal_program( "test28.cpp" )

create_single_source_cgal_program( "test29.cpp" )

create_single_source_cgal_program( "test2.cpp" )

create_single_source_cgal_program( "test30.cpp" )

create_single_source_cgal_program( "test31.cpp" )

create_single_source_cgal_program( "test32.cpp" )

create_single_source_cgal_program( "test33.cpp" )

create_single_source_cgal_program( "test34.cpp" )

create_single_source_cgal_program( "test35.cpp" )

create_single_source_cgal_program( "test36.cpp" )

create_single_source_cgal_program( "test37.cpp" )

create_single_source_cgal_program( "test38.cpp" )

create_single_source_cgal_program( "test39.cpp" )

create_single_source_cgal_program( "test3.cpp" )

create_single_source_cgal_program( "test40.cpp" )

create_single_source_cgal_program( "test41.cpp" )

create_single_source_cgal_program( "test42.cpp" )

create_single_source_cgal_program( "test43.cpp" )

create_single_source_cgal_program( "test44.cpp" )

create_single_source_cgal_program( "test45.cpp" )

create_single_source_cgal_program( "test46.cpp" )

create_single_source_cgal_program( "test47.cpp" )

create_single_source_cgal_program( "test48.cpp" )

create_single_source_cgal_program( "test49.cpp" )

create_single_source_cgal_program( "test4.cpp" )

create_single_source_cgal_program( "test50.cpp" )

create_single_source_cgal_program( "test51.cpp" )

create_single_source_cgal_program( "test52.cpp" )

create_single_source_cgal_program( "test53.cpp" )

create_single_source_cgal_program( "test54.cpp" )

create_single_source_cgal_program( "test55.cpp" )

create_single_source_cgal_program( "test56.cpp" )

create_single_source_cgal_program( "test57.cpp" )

create_single_source_cgal_program( "test58.cpp" )

create_single_source_cgal_program( "test59.cpp" )

create_single_source_cgal_program( "test5.cpp" )

create_single_source_cgal_program( "test60.cpp" )

create_single_source_cgal_program( "test61.cpp" )

create_single_source_cgal_program( "test62.cpp" )

create_single_source_cgal_program( "test63.cpp" )

create_single_source_cgal_program( "test64.cpp" )

create_single_source_cgal_program( "test65.cpp" )

create_single_source_cgal_program( "test66.cpp" )

create_single_source_cgal_program( "test67.cpp" )

create_single_source_cgal_program( "test68.cpp" )

create_single_source_cgal_program( "test6.cpp" )

create_single_source_cgal_program( "test7.cpp" )

create_single_source_cgal_program( "test8.cpp" )

create_single_source_cgal_program( "test9.cpp" )


