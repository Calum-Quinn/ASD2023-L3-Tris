cmake_minimum_required(VERSION 3.16)
project(ASD-Labos-2021)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(L3-demo main_somebits_demo.cpp)

add_executable(program_1 program_1.cpp tri_par_base.h tri_rapide.h)

add_executable(program_2 program_2.cpp tri_par_base.h tri_rapide.h mesure_impl.h mesure.h)