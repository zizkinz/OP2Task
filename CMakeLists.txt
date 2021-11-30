cmake_minimum_required(VERSION 3.20)
project(OP1Task)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "-O3")

add_executable(OP1Task
        main.cpp libai.h studentas.h studentas.cpp)
