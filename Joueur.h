
#include <iostream>
#include <string>
#include "Grille.h"

#ifndef JOUEUR
#define JOUEUR
class Joueur
{
public:
	Joueur(std::string _nom, char _jeton);
	void AfficherNom();
	virtual void Jouer(Grille* grille);
	~Joueur();
	char jeton;

private:
	std::string nom;
};

#endif
