cmake_minimum_required(VERSION 3.6)
project(fakepractice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    egg.c
    sig_num.c)

add_executable(fakepractice ${SOURCE_FILES})