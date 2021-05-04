all: main Grille Joueur JoueurHumain
	g++ main.o Grille.o Joueur.o JoueurHumain.o -o Puissance4

main: main.cpp
	g++ -c main.cpp

Grille: Grille.cpp Grille.h
	g++ -c Grille.cpp

Joueur: Joueur.cpp Joueur.h
	g++ -c Joueur.cpp

JoueurHumain: JoueurHumain.cpp JoueurHumain.h
	g++ -c JoueurHumain.cpp
clean:
	del *.o
	del a.out
