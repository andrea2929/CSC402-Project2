cmake_minimum_required(VERSION 3.6)
project(Project2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp OO_Comparison.cpp OO_Comparison.h Template_Comparison.cpp Template_Comparison.h)
add_executable(Project2 ${SOURCE_FILES})