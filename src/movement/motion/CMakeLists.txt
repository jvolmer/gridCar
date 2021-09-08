target_sources(${LIBRARY} PRIVATE
  motion.hpp
  motionName.hpp
  center.cpp center.hpp
  centerInLeftTurn.cpp centerInLeftTurn.hpp
  centerInRightTurn.cpp centerInRightTurn.hpp
  centerInTurnAround.cpp centerInTurnAround.hpp
  findLine.cpp findLine.hpp
  findNextLineInLeftTurn.cpp findNextLineInLeftTurn.hpp
  findNextLineInRightTurn.cpp findNextLineInRightTurn.hpp
  findNextLineInTurnAround.cpp findNextLineInTurnAround.hpp
  findNextToNextLineInTurnAround.cpp findNextToNextLineInTurnAround.hpp
  leaveLine.cpp leaveLine.hpp
  leaveOriginLineInLeftTurn.cpp leaveOriginLineInLeftTurn.hpp
  leaveOriginLineInRightTurn.cpp leaveOriginLineInRightTurn.hpp
  leaveOriginLineInTurnAround.cpp leaveOriginLineInTurnAround.hpp
  leaveNextLineInTurnAround.cpp leaveNextLineInTurnAround.hpp
  followLine.cpp followLine.hpp
  stop.cpp stop.hpp
  stopFinally.cpp stopFinally.hpp)
