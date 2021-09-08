set(LIBRARY ${CMAKE_PROJECT_NAME}_lib)

add_library(${LIBRARY} STATIC "")
target_compile_options(${LIBRARY} PRIVATE $<$<CONFIG:Debug>:--coverage>)
target_link_options(${LIBRARY} INTERFACE $<$<CONFIG:Debug>:--coverage>)

add_subdirectory(communication)
add_subdirectory(movement)
add_subdirectory(timer)
