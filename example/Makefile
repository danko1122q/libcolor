# Compiler and Flags
CXX      = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
INCLUDES = -I../include
LIB_PATH = ..
LDFLAGS  = -L$(LIB_PATH)
LIBS     = -lcolor

# Files
TARGET   = demo
SRC      = demo.cpp
DEPS     = ../include/color.hpp
STATIC_LIB = ../libcolor.a

# Default rule
all: $(TARGET)

# Link the demo - depends on the source, the header, and the library file
$(TARGET): $(SRC) $(DEPS) $(STATIC_LIB)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) $(LDFLAGS) $(LIBS) -o $(TARGET)

# Run the demo
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET)

.PHONY: all run clean