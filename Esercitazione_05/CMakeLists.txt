cmake_minimum_required(VERSION 3.20)
project(esercitazione2) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

set(SRC_tc misure.cpp)
add_executable(RUN_Misure ${SRC_tc})

set(SRC_tc testMergeSort.cpp)
add_executable(RUN_Merge ${SRC_tc})
add_test(NAME Merge COMMAND RUN_Merge)

set(SRC_tc testQuickSort.cpp)
add_executable(RUN_Quick ${SRC_tc})
add_test(NAME Quick COMMAND RUN_Quick)

enable_testing()