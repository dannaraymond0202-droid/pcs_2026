cmake_minimum_required(VERSION 3.20)
project(esercitazione2) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

set(SRC_tc measure.cpp)
add_executable(RUN ${SRC_tc})


add_executable(Run_Bub test_bubble.cpp)
add_test(NAME Bub COMMAND Run_Bub)

add_executable(Run_Ins test_insertion.cpp)
add_test(NAME Ins COMMAND Run_Ins)

add_executable(Run_Sel test_selection.cpp)
add_test(NAME Sel COMMAND Run_Sel)

enable_testing()