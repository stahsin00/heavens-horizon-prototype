# TODO: from chatgpt
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I src -I src/utils -I src/ai -I src/world -I src/system # TODO: T-T

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Target executable name
TARGET = $(BIN_DIR)/mygame.exe

# Collect all .cpp files in the src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp)
# Create corresponding .o files in the obj directory
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Rule for building the final executable
$(TARGET): $(OBJS)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule for compiling .cpp files to .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove all built files
clean:
	@if exist $(OBJ_DIR) rmdir /S /Q $(OBJ_DIR)
	@if exist $(BIN_DIR) rmdir /S /Q $(BIN_DIR)
