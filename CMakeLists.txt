cmake_minimum_required(VERSION 3.17)
project(Assignment01)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment01 main.cpp matrix.cpp matrix.hpp helper.cpp helper.hpp unit_test.cpp connectivity_matrix.cpp connectivity_matrix.hpp connectivity_uniti_test.cpp importance_matrix.cpp importance_matrix.hpp)