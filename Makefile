include ./common.mk

$(BIN_DIR)/communication/messageOut.test: \
	$(BUILD_DIR)/communication/messageOut_test.o \
	$(BUILD_DIR)/communication/messageOut.o \
	$(BUILD_DIR)/movement/position/coordinate.o \
	$(BUILD_DIR)/movement/position/coordinate_ostream.o \
	$(BUILD_DIR)/communication/coordinateListener.o \
	|$$(@D)/.f
$(BIN_DIR)/communication/messageIn.test: \
	$(BUILD_DIR)/communication/messageIn_test.o \
	$(BUILD_DIR)/communication/messageIn.o \
	$(BUILD_DIR)/movement/position/coordinate.o \
	$(BUILD_DIR)/movement/position/coordinate_ostream.o \
	$(BUILD_DIR)/communication/coordinateBroadcaster.o \
	|$$(@D)/.f

$(BIN_DIR)/movement/position/coordinate.test: \
	$(BUILD_DIR)/movement/position/coordinate_test.o \
	$(BUILD_DIR)/movement/position/coordinate.o \
	$(BUILD_DIR)/movement/position/direction.o \
	$(BUILD_DIR)/movement/position/coordinate_ostream.o \
	|$$(@D)/.f
$(BIN_DIR)/movement/position/direction.test: \
	$(BUILD_DIR)/movement/position/direction_test.o \
	$(BUILD_DIR)/movement/position/direction.o \
	$(BUILD_DIR)/movement/position/direction_ostream.o \
	|$$(@D)/.
$(BIN_DIR)/movement/position/gridPosition.test: \
	$(BUILD_DIR)/movement/position/gridPosition_test.o \
	$(BUILD_DIR)/movement/position/gridPosition.o \
	$(BUILD_DIR)/movement/position/direction.o \
	$(BUILD_DIR)/movement/position/coordinate.o \
	$(BUILD_DIR)/communication/coordinateBroadcaster.o \
	$(BUILD_DIR)/movement/position/direction_ostream.o \
	$(BUILD_DIR)/movement/position/relativeDirection_ostream.o \
	$(BUILD_DIR)/movement/position/coordinate_ostream.o \
	|$$(@D)/.f
$(BIN_DIR)/movement/gridGoal.test: \
	$(BUILD_DIR)/movement/gridGoal_test.o \
	$(BUILD_DIR)/movement/gridGoal.o \
	$(BUILD_DIR)/movement/position/coordinate.o \
	$(BUILD_DIR)/communication/coordinateListener.o \
	$(BUILD_DIR)/movement/position/coordinate_ostream.o \
	$(BUILD_DIR)/movement/position/relativeDirection_ostream.o \
	|$$(@D)/.f

$(BIN_DIR)/movement/motion/stop.test: \
	$(BUILD_DIR)/movement/motion/stop_test.o \
	$(BUILD_DIR)/movement/motion/stop.o \
	$(BUILD_DIR)/movement/position/coordinate.o \
	|$$(@D)/.f
$(BIN_DIR)/movement/motion/followLine.test: \
	$(BUILD_DIR)/movement/motion/followLine_test.o \
	$(BUILD_DIR)/movement/motion/followLine.o \
	$(BUILD_DIR)/movement/position/coordinate.o \
	|$$(@D)/.f
$(BIN_DIR)/movement/motion/leaveOriginLineInRightTurn.test: \
	$(BUILD_DIR)/movement/motion/leaveOriginLineInRightTurn_test.o \
	$(BUILD_DIR)/movement/motion/leaveOriginLineInRightTurn.o \
	$(BUILD_DIR)/movement/motion/leaveLine.o \
	|$$(@D)/.f
$(BIN_DIR)/movement/motion/centerInRightTurn.test: \
	$(BUILD_DIR)/movement/motion/centerInRightTurn_test.o \
	$(BUILD_DIR)/movement/motion/centerInRightTurn.o \
	$(BUILD_DIR)/movement/motion/center.o \
	|$$(@D)/.f
$(BIN_DIR)/movement/motion/findNextLineInRightTurn.test: \
	$(BUILD_DIR)/movement/motion/findNextLineInRightTurn_test.o \
	$(BUILD_DIR)/movement/motion/findNextLineInRightTurn.o \
	$(BUILD_DIR)/movement/motion/findLine.o \
	|$$(@D)/.f
$(BIN_DIR)/movement/linePilot.test: \
	$(BUILD_DIR)/movement/linePilot_test.o \
	$(BUILD_DIR)/movement/linePilot.o \
	$(BUILD_DIR)/movement/motion/stopFinally.o \
	$(BUILD_DIR)/movement/motion/stop.o \
	$(BUILD_DIR)/movement/motion/followLine.o \
	$(BUILD_DIR)/movement/motion/center.o \
	$(BUILD_DIR)/movement/motion/leaveLine.o \
	$(BUILD_DIR)/movement/motion/findLine.o \
	$(BUILD_DIR)/movement/motion/centerInRightTurn.o \
	$(BUILD_DIR)/movement/motion/leaveOriginLineInRightTurn.o \
	$(BUILD_DIR)/movement/motion/findNextLineInRightTurn.o \
	$(BUILD_DIR)/movement/motion/centerInLeftTurn.o \
	$(BUILD_DIR)/movement/motion/leaveOriginLineInLeftTurn.o \
	$(BUILD_DIR)/movement/motion/findNextLineInLeftTurn.o \
	$(BUILD_DIR)/movement/motion/centerInTurnAround.o \
	$(BUILD_DIR)/movement/motion/leaveOriginLineInTurnAround.o \
	$(BUILD_DIR)/movement/motion/findNextLineInTurnAround.o \
	$(BUILD_DIR)/movement/motion/leaveNextLineInTurnAround.o \
	$(BUILD_DIR)/movement/motion/findNextToNextLineInTurnAround.o \
	$(BUILD_DIR)/movement/position/coordinate.o \
	$(BUILD_DIR)/movement/position/direction.o \
	$(BUILD_DIR)/movement/gridGoal.o \
	$(BUILD_DIR)/movement/position/gridPosition.o \
	$(BUILD_DIR)/communication/coordinateListener.o \
	$(BUILD_DIR)/communication/coordinateBroadcaster.o \
	$(BUILD_DIR)/movement/position/gridPosition_ostream.o \
	$(BUILD_DIR)/movement/position/coordinate_ostream.o \
	$(BUILD_DIR)/movement/position/direction_ostream.o \
	|$$(@D)/.f
