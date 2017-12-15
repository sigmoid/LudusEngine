CFLAGS= -std=c++11 -Wall -o game
SDLFLAGS = $(shell sdl2-config --cflags --libs)
CC = g++

all:
	$(CC) $(CFLAGS) vector2.cpp input_manager.cpp program.cpp $(SDLFLAGS)

clean:
	-rm -f *.o
	-rm -f game