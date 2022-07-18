CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -Isrc -Itests -Ilibs/boost_lib/include
LDFLAGS=libs/boost_lib/lib/libboost_json.a -lsfml-graphics -lsfml-window -lsfml-system
test_libs=-Llibs/boost_lib/lib -lboost_unit_test_framework
debug_libs=-g
gprof_libs=-pg -no-pie -fno-builtin

CXXFLAGS+=$(libs)
CXXFLAGS+=$(debug_libs) # Comment this out to disable debug libs
#CXXFLAGS+=$(gprof_libs) # Comment this out to disable gprof libs

game_source := $(wildcard src/*.cpp)
game_source += $(wildcard src/Noise/*.cpp)
game_source += $(wildcard src/Noise/Perlin/*.cpp)
game_source += $(wildcard src/Noise/HighCenter/*.cpp)
test_source := $(wildcard tests/*.cpp)
game_objs := $(game_source:.cpp=.o)
test_objs := $(test_source:.cpp=.o)

# Main targets
island-game: $(game_objs)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

test: $(test_objs) $(filter-out src/main.o, $(game_objs))
	$(CXX) -o $@ $^ $(CXXFLAGS) $(test_libs) $(LDFLAGS)

all: island-game test

.PHONY: docs
docs:
	doxygen dox.config

# Clean
.PHONY: clean
clean:
	-$(RM) $(game_objs) $(test_objs) island-game test gmon.out

.PHONY: clean-docs
clean-docs:
	-$(RM) -r docs/html docs/latex

.PHONY: clean-all
clean-all: clean clean-docs