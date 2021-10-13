cmake_minimum_required(VERSION 3.15)
project(compute_gradient)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(compute_gradient compute_gradient.cpp)
target_link_libraries(compute_gradient ${OpenCV_LIBS})