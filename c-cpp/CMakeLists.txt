cmake_minimum_required(VERSION 3.6)
project(fakepractice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
		egg.cpp
		)

add_executable(fakepractice ${SOURCE_FILES})