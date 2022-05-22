CC=g++
CFLAGS=-g -Wall -Wextra
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
TESTLIBS=-lboost_unit_test_framework


# Main targets
island-game: src/main.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

test-suite: tests/mainTest.o
	$(CC) $(CFLAGS) $(LIBS) $(TESTLIBS) -o $@ $^

all: island-game test-suite


# Object files
mainTest.o: tests/mainTest.cpp
	$(CC) $(CFLAGS) $(LIBS) $(TESTLIBS) -c $^

main.o: src/main.cpp
	$(CC) $(CFLAGS) $(LIBS) -c $^


# Clean
clean:
	rm src/*.o tests/*.o island-game test-suite

