target_sources(${TARGET} PRIVATE
  gridGoal_test.cpp
  linePilot_test.cpp)

add_subdirectory(motion)
add_subdirectory(position)
