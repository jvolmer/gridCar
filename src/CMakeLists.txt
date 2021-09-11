set(LIBRARY ${CMAKE_PROJECT_NAME}_lib)

add_library(${LIBRARY} EXCLUDE_FROM_ALL STATIC "")
target_compile_options(${LIBRARY} PRIVATE $<$<CONFIG:Debug>:--coverage>)
target_link_options(${LIBRARY} INTERFACE $<$<CONFIG:Debug>:--coverage>)

add_subdirectory(communication)
add_subdirectory(movement)
add_subdirectory(timer)

add_custom_target(compile ALL
  COMMAND arduino-cli compile -b ${BOARD_CORE}:${BOARD_NAME} ${CMAKE_SOURCE_DIR})

add_custom_target(upload
  COMMAND arduino-cli upload -p ${PORT} -b ${BOARD_CORE}:${BOARD_NAME} ${CMAKE_SOURCE_DIR}
  DEPENDS compile)
