CXX=g++
CXXFLAGS=-g -Wall -Wextra
libs=-lsfml-graphics -lsfml-window -lsfml-system
test_libs=-lboost_unit_test_framework

game_source := $(wildcard src/*.cpp)
test_source := $(wildcard tests/*.cpp)
game_objs := $(game_source:.cpp=.o)
test_objs := $(test_source:.cpp=.o)

# Main targets
island-game: $(game_objs)
	$(CXX) $(CXXFLAGS) $(libs) -o $@ $^

test-suite: $(test_objs) $(filter-out src/main.o, $(game_objs))
	$(CXX) $(CXXFLAGS) $(libs) $(test_libs) -o $@ $^

all: island-game test-suite

# Clean
clean:
	-rm $(game_objs) $(test_objs) $(game_deps) $(test_deps) island-game test-suite
