target_sources(${LIBRARY} PRIVATE
  goal.hpp
  gridGoal.cpp gridGoal.hpp
  pilot.hpp
  linePilot.cpp linePilot.hpp)

add_subdirectory(motion)
add_subdirectory(motor)
add_subdirectory(position)
add_subdirectory(tracker)
