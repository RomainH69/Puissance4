all: main Grille
	g++ main.o Grille.o -o Puissance4

main: main.cpp
	g++ -c main.cpp

Grille: Grille.cpp Grille.h
	g++ -c Grille.cpp

clean:
	del *.o
	del a.out
