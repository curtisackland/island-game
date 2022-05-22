island-game: main.o
	g++ main.o -o island-game -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp	

clean:
	rm *.o island-game

