cmake_minimum_required(VERSION 3.5.0)
project(UKF)
set(CMAKE_CXX_STANDARD 17)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_subdirectory(say_hello)
add_subdirectory(test)

