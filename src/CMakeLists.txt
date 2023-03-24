cmake_minimum_required(VERSION 3.16)
project(ASD-Labos-2021)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(L3-demo main_somebits_demo.cpp tri_par_base.h tri_rapide.h tri_rapide_impl.h tri_par_base_impl.h)

add_executable(program_1 program_1.cpp)