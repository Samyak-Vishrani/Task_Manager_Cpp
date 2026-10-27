# Build with:  make          (or mingw32-make on Windows)
# Clean with:  make clean

CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp,build/%.o,$(SRCS))
TARGET = build/mini-task-manager

ifeq ($(OS),Windows_NT)
    MKDIR = if not exist build mkdir build
    RMDIR = if exist build rmdir /s /q build
else
    MKDIR = mkdir -p build
    RMDIR = rm -rf build
endif

# Link step: combine all object files into one executable.
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile step: each .cpp becomes its own .o file.
build/%.o: src/%.cpp
	@$(MKDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RMDIR)

.PHONY: clean
