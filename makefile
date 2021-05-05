all: Grille Joueur JoueurHumain JoueurIA Jeu Puissance4 TP_Puissance4
	g++ TP_Puissance4.o Grille.o Joueur.o JoueurHumain.o JoueurIA.o Jeu.o Puissance4.o  -o Puissance4

TP_Puissance4: TP_Puissance4.cpp
	g++ -c TP_Puissance4.cpp

Grille: Grille.cpp Grille.h
	g++ -c Grille.cpp

Joueur: Joueur.cpp Joueur.h
	g++ -c Joueur.cpp

JoueurHumain: JoueurHumain.cpp JoueurHumain.h
	g++ -c JoueurHumain.cpp

JoueurIA: JoueurIA.cpp JoueurIA.h
	g++ -c JoueurIA.cpp

Jeu: Jeu.cpp Jeu.h
	g++ -c Jeu.cpp

Puissance4: Puissance4.o
	g++ -c Puissance4.cpp
clean:
	del *.o
	del a.out

