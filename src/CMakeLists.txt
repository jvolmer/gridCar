set(LIBRARY ${CMAKE_PROJECT_NAME}_lib)

add_library(${LIBRARY} EXCLUDE_FROM_ALL STATIC "")
target_compile_options(${LIBRARY} PRIVATE $<$<CONFIG:Debug>:--coverage>)
target_link_options(${LIBRARY} INTERFACE $<$<CONFIG:Debug>:--coverage>)

add_subdirectory(communication)
add_subdirectory(movement)
add_subdirectory(timer)

set(BOARD_CORE arduino:avr CACHE STRING "Core of board")
set(BOARD_NAME uno CACHE STRING "Type of board")
add_custom_target(configure 
  COMMAND
  arduino-cli core install ${BOARD_CORE} &&
  arduino-cli lib install RF24)

add_custom_target(compile
  COMMAND arduino-cli compile -b ${BOARD_CORE}:${BOARD_NAME} ${CMAKE_SOURCE_DIR})

add_custom_target(upload
  COMMAND arduino-cli upload -p ${PORT} -b ${BOARD_CORE}:${BOARD_NAME} ${CMAKE_SOURCE_DIR}
  DEPENDS compile)
