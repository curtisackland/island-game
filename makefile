CXX=g++
CXXFLAGS=-Wall -Wextra
libs=-lsfml-graphics -lsfml-window -lsfml-system
test_libs=-lboost_unit_test_framework
debug_libs=-g
gprof_libs=-pg -no-pie -fno-builtin

CXXFLAGS+=$(debug_libs) # Comment this out to disable debug libs
CXXFLAGS+=$(gprof_libs) # Comment this out to disable gprof libs

game_source := $(wildcard src/*.cpp)
test_source := $(wildcard tests/*.cpp)
game_objs := $(game_source:.cpp=.o)
test_objs := $(test_source:.cpp=.o)

# Main targets
island-game: $(game_objs)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(libs) 

test: $(test_objs) $(filter-out src/main.o, $(game_objs))
	$(CXX) -o $@ $^ $(CXXFLAGS) $(libs) $(test_libs)

all: island-game test-suite

# Clean
clean:
	-$(RM) $(game_objs) $(test_objs) island-game test-suite gmon.out
