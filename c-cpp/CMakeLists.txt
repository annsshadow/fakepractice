cmake_minimum_required(VERSION 3.6)
project(c_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp multiplication_table.cpp print_year.cpp hanoi.cpp)
add_executable(c_cpp ${SOURCE_FILES})