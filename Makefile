# to modify

# installation locations
ARDUINO_DIR := $(HOME)/bin/arduino-1.8.10
TURTLE_DIR := $(HOME)/bin/turtle_1.3.1
# self-compiled arduino library
ARDUINO_LIB := $(HOME)/lib/arduino/coreObjectFiles/libcore.a

# arduino specifications
F_CPU := 16000000
MCU := atmega328p

# arduino programs

AVR_CC := $(ARDUINO_DIR)/hardware/tools/avr/bin/avr-gcc
AVR_CXX := $(ARDUINO_DIR)/hardware/tools/avr/bin/avr-g++
AVR_AR := $(ARDUINO_DIR)/hardware/tools/avr/bin/avr-ar
AVR_OBJCOPY := $(ARDUINO_DIR)/hardware/tools/avr/bin/avr-objcopy
AVR_DUDE := $(ARDUINO_DIR)/hardware/tools/avr/bin/avrdude

# project-directories

PROJECT_DIR := .
SRC_DIR := src
TEST_DIR := test
BUILD_DIR := build
BIN_DIR := bin

# compiler flags

GENERAL_FLAGS := -std=gnu++14 -Wall

AVRCOMPILE_FLAGS = -x c++ -ffunction-sections -fdata-sections -mmcu=$(MCU) -DF_CPU=$(F_CPU)L -Os -include Arduino.h -MT $@ -MMD -MP -MF $(@:%.avr_o=%.d) $(GENERAL_FLAGS)
AVRLINK_FLAGS := -mmcu=$(MCU) -Wl,--gc-sections -Os 
AVR_INC := -I $(ARDUINO_DIR)/hardware/arduino/avr/cores/arduino/ -I $(ARDUINO_DIR)/hardware/arduino/avr/variants/standard
AVRDUDE_CONF := $(ARDUINO_DIR)/hardware/tools/avr/etc/avrdude.conf

CXX := g++
CXX_FLAGS = -Wall -Wno-deprecated-declarations -MT $@ -MMD -MP -MF $(@:%.o=%.d) $(GENERAL_FLAGS)
LDFLAGS  := -lboost_unit_test_framework -lm
CXX_INC := -I $(TURTLE_DIR)/include

# files
SRC_EXT := cpp

TARGET_NAME := $(shell basename $(PWD))
SRC_MAIN := $(TARGET_NAME).ino
TARGET := $(BIN_DIR)/$(TARGET_NAME).hex
TARGET_ELF := $(TARGET:.hex=.elf)

SRC := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
AVR_OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRC:.$(SRC_EXT)=.avr_o)) $(BUILD_DIR)/$(TARGET_NAME).avr_o
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRC:.$(SRC_EXT)=.o))

TESTS := $(shell find $(TEST_DIR) -type f -name *_test.$(SRC_EXT))
TEST_TARGETS := $(patsubst $(TEST_DIR)/%,$(BIN_DIR)/%,$(TESTS:_test.$(SRC_EXT)=.test))
TEST_OBJECTS := $(patsubst $(TEST_DIR)/%,$(BUILD_DIR)/%,$(TESTS:.$(SRC_EXT)=.o))

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

# # upload to arduino

upload : $(TARGET)
	$(AVR_DUDE) -C$(AVRDUDE_CONF) -v -p$(MCU) -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:$<:i

# arduino compilation

$(BIN_DIR)/%.hex : $(BIN_DIR)/%.elf |$$(@D)/.f
	$(AVR_OBJCOPY) -O ihex -R .eeprom $< $@

$(BIN_DIR)/$(TARGET_NAME).elf : $(AVR_OBJECTS) |$$(@D)/.f
	$(AVR_CC) $(AVRLINK_FLAGS) -o $@ $^ $(ARDUINO_LIB) -lc -lm

$(BUILD_DIR)/$(TARGET_NAME).avr_o : $(PROJECT_DIR)/$(SRC_MAIN) |$$(@D)/.f
	$(AVR_CXX) $(AVR_INC) $(AVRCOMPILE_FLAGS) $< -c -o $@

$(BUILD_DIR)/%.avr_o : $(SRC_DIR)/%.cpp |$$(@D)/.f
	$(AVR_CXX) $(AVR_INC) $(AVRCOMPILE_FLAGS) $< -c -o $@

# test compilation

tests : $(TEST_TARGETS)

$(BIN_DIR)/%.test : $(BUILD_DIR)/%_test.o $(BUILD_DIR)/%.o |$$(@D)/.f
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LDFLAGS)
	@echo Running $@
	@./$@ #--log_level=test_suite
	@echo

$(BIN_DIR)/controller/communicatorHeadquaters.test: $(BUILD_DIR)/controller/communicatorHeadquaters_test.o $(BUILD_DIR)/controller/communicatorHeadquaters.o $(BUILD_DIR)/entity/transmission.o $(BUILD_DIR)/entity/coordinate.o $(BUILD_DIR)/entity/IOOperatorOverloading.o |$$(@D)/.f
$(BIN_DIR)/controller/mover.test: $(BUILD_DIR)/controller/mover_test.o $(BUILD_DIR)/controller/mover.o $(BUILD_DIR)/entity/coordinate.o $(BUILD_DIR)/entity/direction.o $(BUILD_DIR)/entity/IOOperatorOverloading.o |$$(@D)/.f
$(BIN_DIR)/entity/coordinate.test: $(BUILD_DIR)/entity/coordinate_test.o $(BUILD_DIR)/entity/coordinate.o $(BUILD_DIR)/entity/direction.o $(BUILD_DIR)/entity/IOOperatorOverloading.o |$$(@D)/.f
$(BIN_DIR)/entity/direction.test: $(BUILD_DIR)/entity/direction_test.o $(BUILD_DIR)/entity/direction.o $(BUILD_DIR)/entity/IOOperatorOverloading.o |$$(@D)/.f


$(BUILD_DIR)/%_test.o : $(TEST_DIR)/%_test.cpp |$$(@D)/.f
	$(CXX) $(CXX_FLAGS) $< -I $(PROJECT_DIR) $(CXX_INC) -c -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp |$$(@D)/.f
	$(CXX) $(CXX_FLAGS) $< -I $(PROJECT_DIR) -c -o $@

$(BUILD_DIR)/%.o : $(TEST_DIR)/%.cpp |$$(@D)/.f
	$(CXX) $(CXX_FLAGS) $< -I $(PROJECT_DIR) $(CXX_INC) -c -o $@

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
.PHONY : upload clean tests
# targets that are not explicitly named in Makefile should not automatically be deleted
.SECONDARY : $(TARGET_ELF) $(TARGET) $(AVR_OBJECTS) $(OBJECTS) $(TEST_OBJECTS)
# similar to .secondary, but works with patterns and targets are additionally not deleted when make is killed or interrupted
.PRECIOUS: %/.f
