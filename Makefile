CXX      ?= g++
CXXFLAGS ?= -std=c++11 -Wall -Wextra -O2
AR       ?= ar
ARFLAGS  := rcs
PREFIX   ?= /usr/local

INC_DIR  := include
SRC_DIR  := src
OBJ_DIR  := build
LIB_DIR  := .

TARGET_A  := libcolor.a
TARGET_SO := libcolor.so

SRC      := $(SRC_DIR)/color.cpp
OBJ      := $(OBJ_DIR)/color.o


.PHONY: all
all: $(TARGET_A)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ): $(SRC) $(INC_DIR)/color.hpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(TARGET_A): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^
	@echo "Built $(TARGET_A)"


.PHONY: shared
shared: CXXFLAGS += -fPIC
shared: $(OBJ)
	$(CXX) -shared -o $(TARGET_SO) $(OBJ)
	@echo "Built $(TARGET_SO)"


.PHONY: example
example: $(TARGET_A)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) example/demo.cpp -L. -lcolor -o example/demo
	./example/demo


.PHONY: install
install: $(TARGET_A)
	install -d $(PREFIX)/lib $(PREFIX)/include
	install -m 644 $(TARGET_A) $(PREFIX)/lib/
	install -m 644 $(INC_DIR)/color.hpp $(PREFIX)/include/
	@echo "Installed to $(PREFIX)"

.PHONY: install-shared
install-shared: shared
	install -d $(PREFIX)/lib $(PREFIX)/include
	install -m 755 $(TARGET_SO) $(PREFIX)/lib/
	install -m 644 $(INC_DIR)/color.hpp $(PREFIX)/include/
	ldconfig $(PREFIX)/lib
	@echo "Installed shared lib to $(PREFIX)"

.PHONY: uninstall
uninstall:
	rm -f $(PREFIX)/lib/$(TARGET_A) $(PREFIX)/lib/$(TARGET_SO)
	rm -f $(PREFIX)/include/color.hpp
	@echo "Uninstalled"

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(TARGET_A) $(TARGET_SO) example/demo
	@echo "Cleaned"
