CC = g++

CPPFLAGS = -std=c++17 -Wall
INCLUDES = -Isrc

SRC_DIR = src
BUILD_DIR = build
ASSETS_DIR = assets
BINARY_DIR = bin

TARGET = $(BINARY_DIR)/spell_checker
DICTIONARY_DEST = $(BINARY_DIR)/dictionary.txt
DICTIONARY_TARGET = $(ASSETS_DIR)/words_alpha.txt

SOURCES = $(shell find $(SRC_DIR) -type f -name '*.cpp' -o -name '*.hpp')

OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(filter %.cpp, $(SOURCES)))

all: $(TARGET) $(DICTIONARY_DEST)

$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

$(DICTIONARY_DEST): $(DICTIONARY_TARGET)
	@mkdir -p $(dir $@)
	cp $< $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(BINARY_DIR)
