EXE := RpgEngine.out
SRC := $(wildcard *.cpp) $(wildcard */*.cpp)
OBJDIR := build
OBJ := $(SRC:.cpp=.o)
CXX_FLAGS := --std=c++11

all: $(EXE)

clean:
	rm -rf $(OBJ)
	rm -rf $(EXE)

$(EXE): $(OBJ)
	g++ $(CXX_FLAGS) -o $@ $^

%.o: %.cpp
	g++ -c $(CXX_FLAGS) -o $@ $<