
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class Joueur;
class JoueurHumain;
#ifndef GRILLE
#define GRILLE

class Grille
{
public:
	Grille();
	Grille(Grille const& grilleCopie);
	void Afficher();
	void Afficher_choix(int colonne, char jeton);
	void Initialiser();
	bool ColonnePleine(int colonne);
	char Gagne();
	void AjouterJeton(int _colonne, char _jeton);
	~Grille();

private:
	char grille[6][7];
	int colonne=0;
	int ligne = 0;
	char* tab[6];
};

#endif
