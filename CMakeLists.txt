cmake_minimum_required(VERSION 3.8)
project(Turing_Award)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp sources/A.hpp sources/B.hpp sources/C.hpp sources/D.hpp sources/E.hpp config.hpp test_lib.hpp lib.hpp)
add_executable(Turing_Award ${SOURCE_FILES})