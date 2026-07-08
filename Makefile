# Compiler and flags
CXX      := g++
CXXFLAGS := -Wall

# Directories
SRC_DIR   := src
INC_DIR   := include
BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/obj

# Target executable path
TARGET    := $(BUILD_DIR)/marathon

# Find all .cpp files in the src directory
SRCS      := $(wildcard $(SRC_DIR)/*.cpp)

# Map those .cpp files to .o files inside build/obj/
OBJS      := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Include flags for header search path
CPPFLAGS  := -I$(INC_DIR)

# Default rule
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

# Create directories if they do not exist
$(BUILD_DIR) $(OBJ_DIR):
	mkdir -p $@

# Clean rule to wipe the entire build output
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

