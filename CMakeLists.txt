cmake_minimum_required(VERSION 3.13)
project(GridCar
  VERSION 1.0)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

set(CMAKE_CXX_STANDARD 14)

set(BOARD_CORE arduino:avr CACHE STRING "Core of board")
set(BOARD_NAME uno CACHE STRING "Name of board")
set(PORT /dev/ttyACM0 CACHE STRING "Port for upload")
add_custom_target(configure 
  COMMAND
  arduino-cli core install ${BOARD_CORE} &&
  arduino-cli lib install RF24)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(control)
