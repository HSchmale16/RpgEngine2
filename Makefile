EXE := RpgEngine.out
CXX_SRC := $(wildcard *.cpp) $(wildcard src/*.cpp) 
C_SRC 	:= $(wildcard lib/*.c)
HEADERS := $(wildcard include/*)
OBJDIR := build
OBJ := $(CXX_SRC:.cpp=.o) $(C_SRC:.c=.o)
CXX_FLAGS := -g --std=c++17 -Wall -Werror
C_FLAGS = -D_GNU_SOURCE -std=c99


.PHONY: all
all: depend $(EXE)

.PHONY: clean
clean:
	rm -rf $(OBJ)
	rm -rf $(EXE)

$(EXE): $(OBJ)
	g++ $(CXX_FLAGS) -o $@ $^ $(LD_FLAGS)

%.o: %.cpp
	$(CXX) -c $(CXX_FLAGS) -o $@ $<

%.o: %.c
	$(CC) $(C_FLAGS) -c -o $@ $<

.PHONY: depend
depend: .depend

.depend: $(C_SRC) $(CXX_SRC) $(HEADERS)
	rm -f $@
	$(CXX) $(CXX_FLAGS) -MT $^ > $@

include .depend
