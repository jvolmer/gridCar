# to modify

# installation locations
ARDUINO_DIR := $(HOME)/bin/arduino-1.8.10
TURTLE_DIR := $(HOME)/bin/turtle_1.3.1
# self-compiled arduino library
ARDUINO_LIB := $(HOME)/lib/arduino/coreObjectFiles/libcore_withCommunication.a

# arduino specifications

# arduino specific
MCU := atmega328p
F_CPU := 16000000
BAUDRATE := 115200
PROGRAMMER := arduino
# system specific
PORT := /dev/ttyACM0

# programs

AVR_CC := $(ARDUINO_DIR)/hardware/tools/avr/bin/avr-gcc
AVR_CXX := $(ARDUINO_DIR)/hardware/tools/avr/bin/avr-g++
AVR_AR := $(ARDUINO_DIR)/hardware/tools/avr/bin/avr-ar
AVR_OBJCOPY := $(ARDUINO_DIR)/hardware/tools/avr/bin/avr-objcopy
AVR_DUDE := $(ARDUINO_DIR)/hardware/tools/avr/bin/avrdude
CXX := g++

# project-directories

PROJECT_DIR := .
SRC_DIR := src
TEST_DIR := test
BUILD_DIR := build
BIN_DIR := bin

# compiler flags

COMPILE_FLAGS := -std=gnu++14 -Os -Wall
AVRCOMPILE_FLAGS = $(COMPILE_FLAGS) -MT $@ -MMD -MP -MF $(@:%.avr_o=%.d) -x c++ -ffunction-sections -fdata-sections -mmcu=$(MCU) -DF_CPU=$(F_CPU)L -include Arduino.h
CXX_FLAGS = $(COMPILEL_FLAGS) -MT $@ -MMD -MP -MF $(@:%.o=%.d) -Wno-deprecated-declarations
AVRLD_FLAGS := -Wl,--gc-sections -mmcu=$(MCU) -lc -lm
LDFLAGS  := -lboost_unit_test_framework -lm
AVRDUDE_FLAGS := -v -p$(MCU) -c$(PROGRAMMER) -P$(PORT) -b$(BAUDRATE) -D
AVRCOPY_FLAGS := -O ihex -R .eeprom

AVR_INC := -I$(ARDUINO_DIR)/hardware/arduino/avr/cores/arduino/ -I$(ARDUINO_DIR)/hardware/arduino/avr/variants/standard -I$(ARDUINO_DIR)/hardware/arduino/avr/libraries/RF24 -I$(ARDUINO_DIR)/hardware/arduino/avr/libraries/SPI/src
CXX_INC := -I$(TURTLE_DIR)/include
AVRDUDE_CONF := $(ARDUINO_DIR)/hardware/tools/avr/etc/avrdude.conf

# files

TARGET_NAME := $(shell basename $(PWD))
SRC_MAIN := $(TARGET_NAME).ino
TARGET := $(BIN_DIR)/$(TARGET_NAME).hex
TARGET_ELF := $(TARGET:.hex=.elf)

SRC := $(shell find $(SRC_DIR) -type f -name *.cpp)
AVR_OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRC:.cpp=.avr_o)) $(BUILD_DIR)/$(TARGET_NAME).avr_o
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRC:.cpp=.o))

TESTS := $(shell find $(TEST_DIR) -type f -name *_test.cpp)
TEST_TARGETS := $(patsubst $(TEST_DIR)/%,$(BIN_DIR)/%,$(TESTS:_test.cpp=.test))
TEST_OBJECTS := $(patsubst $(TEST_DIR)/%,$(BUILD_DIR)/%,$(TESTS:.cpp=.o))

# fill depfiles if build_dir exists
ifeq ($(wildcard $(BUILD_DIR)/),)
	DEPFILES :=
else
	DEPFILES := $(shell find $(BUILD_DIR) -type f -name *.d)
endif

# use secondexpansion (needed to create directories)
.SECONDEXPANSION:

# target

$(TARGET) :

# arduino compilation

$(BIN_DIR)/%.hex : $(BIN_DIR)/%.elf |$$(@D)/.f
	$(AVR_OBJCOPY) $(AVRCOPY_FLAGS) $< $@

$(BIN_DIR)/$(TARGET_NAME).elf : $(AVR_OBJECTS) |$$(@D)/.f
	$(AVR_CC) $^ -o $@ $(ARDUINO_LIB)  $(AVRLD_FLAGS)

$(BUILD_DIR)/$(TARGET_NAME).avr_o : $(PROJECT_DIR)/$(SRC_MAIN) |$$(@D)/.f
	$(AVR_CXX) $(AVR_INC) $(AVRCOMPILE_FLAGS) $< -c -o $@

$(BUILD_DIR)/%.avr_o : $(SRC_DIR)/%.cpp |$$(@D)/.f
	$(AVR_CXX) $(AVR_INC) $(AVRCOMPILE_FLAGS) $< -c -o $@

# test compilation

test : $(TEST_TARGETS)

$(BIN_DIR)/%.test : $(BUILD_DIR)/%_test.o $(BUILD_DIR)/%.o |$$(@D)/.f
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LDFLAGS)
	@echo Running $@
	@./$@ --list_content
	@./$@
	@echo

# $(BIN_DIR)/communication/communicatorHeadquaters.test: $(BUILD_DIR)/communication/communicatorHeadquaters_test.o $(BUILD_DIR)/communication/communicatorHeadquaters.o $(BUILD_DIR)/communication/transmission.o $(BUILD_DIR)/movement/position/coordinate.o $(BUILD_DIR)/communication/transmission_ostream.o |$$(@D)/.f
$(BIN_DIR)/communication/messageFromCar.test: $(BUILD_DIR)/communication/messageFromCar_test.o $(BUILD_DIR)/communication/messageFromCar.o $(BUILD_DIR)/movement/position/coordinate.o $(BUILD_DIR)/movement/position/coordinate_ostream.o |$$(@D)/.f
$(BIN_DIR)/movement/stop.test: $(BUILD_DIR)/movement/stop_test.o $(BUILD_DIR)/movement/stop.o $(BUILD_DIR)/movement/position/coordinate.o |$$(@D)/.f
$(BIN_DIR)/movement/followLine.test: $(BUILD_DIR)/movement/followLine_test.o $(BUILD_DIR)/movement/followLine.o $(BUILD_DIR)/movement/position/coordinate.o |$$(@D)/.f
$(BIN_DIR)/movement/turnRightFromLine.test: $(BUILD_DIR)/movement/turnRightFromLine_test.o $(BUILD_DIR)/movement/turnRightFromLine.o |$$(@D)/.f
$(BIN_DIR)/movement/alignInRightTurn.test: $(BUILD_DIR)/movement/alignInRightTurn_test.o $(BUILD_DIR)/movement/alignInRightTurn.o |$$(@D)/.f
$(BIN_DIR)/movement/turnRightToLine.test: $(BUILD_DIR)/movement/turnRightToLine_test.o $(BUILD_DIR)/movement/turnRightToLine.o |$$(@D)/.f
$(BIN_DIR)/movement/linePilot.test: $(BUILD_DIR)/movement/linePilot_test.o $(BUILD_DIR)/movement/linePilot.o $(BUILD_DIR)/movement/stop.o $(BUILD_DIR)/movement/followLine.o $(BUILD_DIR)/movement/turnRightFromLine.o $(BUILD_DIR)/movement/alignInRightTurn.o $(BUILD_DIR)/movement/turnRightToLine.o $(BUILD_DIR)/movement/turnLeftFromLine.o $(BUILD_DIR)/movement/alignInLeftTurn.o $(BUILD_DIR)/movement/turnLeftToLine.o $(BUILD_DIR)/movement/position/coordinate.o |$$(@D)/.f
# $(BIN_DIR)/movement/lineSteering.test: $(BUILD_DIR)/movement/lineSteering_test.o $(BUILD_DIR)/movement/lineSteering.o $(BUILD_DIR)/movement/position/coordinate.o |$$(@D)/.f
$(BIN_DIR)/movement/position/coordinate.test: $(BUILD_DIR)/movement/position/coordinate_test.o $(BUILD_DIR)/movement/position/coordinate.o $(BUILD_DIR)/movement/position/direction.o $(BUILD_DIR)/movement/position/coordinate_ostream.o |$$(@D)/.f
$(BIN_DIR)/movement/position/direction.test: $(BUILD_DIR)/movement/position/direction_test.o $(BUILD_DIR)/movement/position/direction.o $(BUILD_DIR)/movement/position/direction_ostream.o |$$(@D)/.
$(BIN_DIR)/movement/position/gridPosition.test: $(BUILD_DIR)/movement/position/gridPosition_test.o $(BUILD_DIR)/movement/position/direction.o $(BUILD_DIR)/movement/position/coordinate.o $(BUILD_DIR)/movement/position/direction_ostream.o $(BUILD_DIR)/movement/position/coordinate_ostream.o |$$(@D)/.f


$(BUILD_DIR)/%_test.o : $(TEST_DIR)/%_test.cpp |$$(@D)/.f
	$(CXX) $(CXX_FLAGS) $< $(CXX_INC) -I$(PROJECT_DIR) -c -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp |$$(@D)/.f
	$(CXX) $(CXX_FLAGS) $< -I$(PROJECT_DIR) -c -o $@

$(BUILD_DIR)/%.o : $(TEST_DIR)/%.cpp |$$(@D)/.f
	$(CXX) $(CXX_FLAGS) $< $(CXX_INC) -I$(PROJECT_DIR) -c -o $@

# # upload to arduino

upload : $(TARGET)
	$(AVR_DUDE) -C$(AVRDUDE_CONF) $(AVRDUDE_FLAGS) -Uflash:w:$<:i

# Makefile stuff

# use .d (dependency) files for prerequisite generation
$(DEPFILES):
include $(wildcard $(DEPFILES))

# create directory if not present (if dir/.f does not exist)
%/.f:
	mkdir -p $(dir $@)
	touch $@

clean : 
	rm -rf $(BUILD_DIR)/* $(TARGET) $(TARGET_ELF) $(TEST_TARGETS)

# targets that are not files
.PHONY : upload clean test
# targets that are not explicitly named in Makefile should not automatically be deleted
.SECONDARY : $(TARGET_ELF) $(TARGET) $(AVR_OBJECTS) $(OBJECTS) $(TEST_OBJECTS)
# similar to .secondary, but works with patterns and targets are additionally not deleted when make is killed or interrupted
.PRECIOUS: %/.f
