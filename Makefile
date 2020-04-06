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

# project-directories

SRC_DIR := src
TEST_DIR := test
BUILD_DIR := build
BIN_DIR := bin

# files
SRC_EXT := cpp
TARGET := $(BIN_DIR)/main.hex

TARGET_ELF := $(TARGET:.hex=.elf)
SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
AVR_OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.avr_o))
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.o))

TESTS := $(shell find $(TEST_DIR) -type f -name *.$(SRC_EXT))
TEST_TARGETS := $(patsubst $(TEST_DIR)/test_%,$(BIN_DIR)/%,$(TESTS:.cpp=.test))
TEST_OBJECTS := $(patsubst $(TEST_DIR)/%,$(BUILD_DIR)/%,$(TESTS:.$(SRC_EXT)=.o))

DEPFILES := $(shell find $(BUILD_DIR) -type f -name *.d)

# target

$(TARGET) :

# upload to arduino

upload_% : %.hex
	$(AVR_DUDE) -C$(AVRDUDE_CONF) -v -p$(MCU) -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:$<:i

# arduino compilation

$(BIN_DIR)/%.hex : $(BIN_DIR)/%.elf
	$(AVR_OBJCOPY) -O ihex -R .eeprom $< $@

$(BIN_DIR)/%.elf : $(AVR_OBJECTS)
	$(AVR_CC) $(AVRLINK_FLAGS) -o $@ $^ $(ARDUINO_LIB) -lc -lm

$(BUILD_DIR)/%.avr_o : $(SRC_DIR)/%.cpp
	$(AVR_CXX) $(AVR_INC) $(AVRCOMPILE_FLAGS) $< -c -o $@

# test compilation

tests : $(TEST_TARGETS)

$(BIN_DIR)/%.test : $(BUILD_DIR)/test_%.o $(BUILD_DIR)/%.o
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LDFLAGS)
	@echo Running $@
	@./$@ #--log_level=test_suite
	@echo 

$(BUILD_DIR)/test_%.o : $(TEST_DIR)/test_%.cpp
	$(CXX) $(CXX_FLAGS) $< -I $(SRC_DIR) $(CXX_INC) -c -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXX_FLAGS) $< -c -o $@

# Makefile stuff

# use .d (dependency) files for prerequisite generation
$(DEPFILES):
include $(wildcard $(DEPFILES))

clean : 
	rm -f $(BUILD_DIR)/* $(TARGET) $(TARGET_ELF) $(TEST_TARGETS)

# targets that are not files
.PHONY : upload clean tests
# targets that are not explicitly named in Makefile should not automatically be deleted
.SECONDARY : $(TARGET_ELF) $(TARGET) $(AVR_OBJECTS) $(OBJECTS) $(TEST_OBJECTS)
