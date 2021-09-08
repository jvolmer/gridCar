cmake_minimum_required(VERSION 3.13)
project(GridCar
  VERSION 1.0)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
# include(variables.cmake)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src)
add_subdirectory(test)
