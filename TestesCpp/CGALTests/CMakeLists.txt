# Created by the script cgal_create_CMakeLists
# This is the CMake script for compiling a set of CGAL applications.

cmake_minimum_required(VERSION 3.1...3.15)

project( CGALTests )


# CGAL and its components
find_package( CGAL QUIET COMPONENTS Qt5 )

if ( NOT CGAL_FOUND )

  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()  

endif()

add_definitions(-DCGAL_USE_BASIC_VIEWER)
add_definitions(-fopenmp)

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


create_single_source_cgal_program( "test1.cpp" )

create_single_source_cgal_program( "test3.cpp" )

create_single_source_cgal_program( "test4.cpp" )

create_single_source_cgal_program( "test5-2.cpp" )

create_single_source_cgal_program( "test5.cpp" )

create_single_source_cgal_program( "test6.cpp" )


