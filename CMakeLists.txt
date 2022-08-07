cmake_minimum_required(VERSION 3.21)


set(CMAKE_CXX_STANDARD 20)

project(GMath)
add_executable(Test test/test.cpp)

target_include_directories(Test PUBLIC gmath/include)