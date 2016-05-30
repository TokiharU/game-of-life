.PHONY: clean prepare app

bin/proj: prepare obj/main.o obj/Game.o
	g++ -Wall -o bin/proj obj/main.o obj/Game.o

obj/main.o: prepare scr/main.cpp
	g++ -o obj/main.o -c scr/main.cpp

obj/Game.o: prepare scr/Game.cpp
	g++ -o obj/Game.o -c scr/Game.cpp

prepare: bin obj

app: bin/proj
	bin/proj

bin:
	mkdir bin

obj:
	mkdir obj



clean:
	rm -f bin/proj obj/main.o obj/Game.o