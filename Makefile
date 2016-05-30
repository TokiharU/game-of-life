.PHONY: clean

bin/proj: obj/main.o obj/Game.o
	g++ -Wall -o bin/proj obj/main.o obj/Game.o

obj/main.o: scr/main.cpp
	g++ -o obj/main.o -c scr/main.cpp

obj/Game.o: scr/Game.cpp
	g++ -o obj/Game.o -c scr/Game.cpp

clean:
	rm -f bin/proj obj/main.o obj/Game.o