set(TARGET ${CMAKE_PROJECT_NAME}_test)

add_executable(${TARGET} EXCLUDE_FROM_ALL main_test.cpp)

find_package(turtle REQUIRED)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
target_link_libraries (${TARGET} PRIVATE ${CMAKE_PROJECT_NAME}_lib Boost::unit_test_framework turtle::turtle)
target_include_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR})

add_custom_target(test COMMAND ${TARGET}
  COMMENT "Execute tests")

add_subdirectory(communication)
add_subdirectory(movement)
