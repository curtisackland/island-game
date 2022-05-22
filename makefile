island-game: src/main.o
	g++ src/main.o -o island-game -lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp
	g++ -c src/main.cpp	

clean:
	rm src/*.o island-game

