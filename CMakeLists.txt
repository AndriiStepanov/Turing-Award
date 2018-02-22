cmake_minimum_required(VERSION 3.8)
project(Turing_Award)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES template.hpp task.cpp lib.hpp)
add_executable(Turing_Award ${SOURCE_FILES})