# File: Makefile
# Author(s): Caleb Johnson-Cantrell

# Tool and option configuration
CXX      = g++
CXXFLAGS = -Wall -Werror --pedantic-errors -g -std=c++17
MKDIR    = mkdir
RM       = rm
RMFLAGS  = -rf

# Files and directories
EXE = emulator
SRC = src
OBJ = obj
BIN = bin
INC = src/include

SOURCES = $(wildcard $(SRC)/*.cpp)
OBJECTS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))

.PHONY: all
all: $(EXE)

# Executable build rule
$(EXE): $(OBJECTS) | $(BIN)
	$(CXX) $(CXXFLAGS) -I$(INC) -o $(BIN)/$@ $^

# Generic build rule, .cpp files with headers
$(OBJ)/%.o: $(SRC)/%.cpp $(INC)/%.hpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INC) -c $< -o $@

# Generic build rule, .cpp files without headers
$(OBJ)/%.o: $(SRC)/%.cpp | $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INC) -c $< -o $@

# Folder creation rule
$(BIN) $(OBJ):
	$(MKDIR) $@

clean:
	$(RM) $(RMFLAGS) bin obj
