#makefile for Solar
#openGL orery

OBJECTS = main.o Colour.o Planet.o 
CFLAGS = -c -Wdeprecated-declarations

all: Solar

Solar: main.o Colour.o Planet.o
	g++ main.o Colour.o Planet.o -o Solar -framework OpenGL -framework GLUT

main.o: main.cpp
	g++ $(CFLAGS) main.cpp

Colour.o: Colour.cpp
	g++ $(CFLAGS) Colour.cpp

Planet.o: Planet.cpp
	g++ $(CFLAGS) Planet.cpp

clean:
	rm -rf *o Solar
