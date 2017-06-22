EXE 		:= RpgEngine.out
CXX_FLAGS 	:= -g --std=c++17 -Wall -Werror
C_FLAGS 	:= -D_GNU_SOURCE -std=c99

CXX_SRC := $(wildcard *.cpp) $(wildcard src/*.cpp) 
C_SRC 	:= $(wildcard lib/*.c)
HEADERS := $(wildcard include/*)

OBJ := $(CXX_SRC:.cpp=.cpp.o) $(C_SRC:.c=.c.o)

.PHONY: all
all: $(EXE)

.PHONY: clean
clean:
	rm -rf $(OBJ)
	rm -rf $(EXE)
	rm -f $(OBJ:.o=.d)

$(EXE): $(OBJ)
	g++ $(CXX_FLAGS) -o $@ $^ $(LD_FLAGS)

%.cpp.o: %.cpp
	$(CXX) $(CXX_FLAGS) -MM -MF $(patsubst %.o,%.d,$@)  -c -o $@ $<

%.c.o: %.c
	$(CC) $(C_FLAGS) -c -MM -MF $(patsubst %.o,%.d,$@) -o $@ $<

-include $(OBJ:.o=.d)