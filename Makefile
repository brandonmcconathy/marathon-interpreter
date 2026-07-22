# Directories
SRC_DIR   := src
INC_DIR   := include
BUILD_DIR := bin
OBJ_DIR   := $(BUILD_DIR)/obj
TEST_DIR  := tests

# Compiler and flags
CXX      := g++
CXXFLAGS := -Wall -std=c++26 -I$(INC_DIR)
GTEST_LIBS := -lgtest -lgtest_main -pthread

# Target executable path
TARGET    := $(BUILD_DIR)/marathon
TEST_TARGET := $(BUILD_DIR)/run_tests

# Find all .cpp files in the src directory
ALL_SRCS  := $(wildcard $(SRC_DIR)/*.cpp)
CORE_SRCS := $(filter-out $(SRC_DIR)/main.cpp, $(ALL_SRCS))
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)

# Map those .cpp files to .o files inside build/obj/
CORE_OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CORE_SRCS))
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(TEST_SRCS))

# Default target
all: $(TARGET) $(TEST_TARGET)

# Build the production binary
$(TARGET): $(SRC_DIR)/main.cpp $(CORE_OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< $(CORE_OBJS) -o $@

# Build the test binary
$(TEST_TARGET): $(TEST_OBJS) $(CORE_OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ $(GTEST_LIBS) -o $@

# Compile .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile tests .cpp files into .o files
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create directories if they do not exist
$(BUILD_DIR) $(OBJ_DIR):
	mkdir -p $@

# Run tests directly
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean rule to wipe the entire build output
clean:
	rm -rf $(BUILD_DIR)

-include $(CORE_OBJS:.o=.d) $(TEST_OBJS:.o=.d) $(OBJ_DIR)/main.d

.PHONY: all test clean

