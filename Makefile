EXE := RpgEngine.out
SRC := $(wildcard *.cpp) $(wildcard */*.cpp)
HEADERS := $(wildcard include/*)
OBJDIR := build
OBJ := $(SRC:.cpp=.o)
CXX_FLAGS := -g --std=c++11

.PHONY: all
all: depend $(EXE)

.PHONY: clean
clean:
	rm -rf $(OBJ)
	rm -rf $(EXE)

$(EXE): $(OBJ)
	g++ $(CXX_FLAGS) -o $@ $^

%.o: %.cpp
	g++ -c $(CXX_FLAGS) -o $@ $<

.PHONY: depend
depend: .depend

.depend: $(SRC) $(HEADERS)
	rm -f $@
	$(CXX) $(CXXFLAGS) -MM $^ > $@

include .depend
