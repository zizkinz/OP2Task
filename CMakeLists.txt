cmake_minimum_required(VERSION 3.20)
project(OP1Task)

set(CMAKE_CXX_STANDARD 14)

add_executable(OP1Task
        main.cpp libai.h studentas.h median.cpp median.h generate.h mean.h printas.h comparator.h generate.cpp printas.cpp mean.cpp writeas.cpp writeas.h comparator.cpp binsearch.h binsearch.cpp)
