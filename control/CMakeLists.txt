add_custom_target(compile_control
  COMMAND arduino-cli compile -b ${BOARD_CORE}:${BOARD_NAME} ${CMAKE_SOURCE_DIR}/control)

add_custom_target(upload_control
  COMMAND arduino-cli upload -p ${PORT} -b ${BOARD_CORE}:${BOARD_NAME} ${CMAKE_SOURCE_DIR}/control
  DEPENDS compile_control)
