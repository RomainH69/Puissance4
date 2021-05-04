#include "Joueur.h"


Joueur::Joueur(std::string _nom, char _jeton)
{
	nom = nom;
	jeton = _jeton;
}

void Joueur::AfficherNom()
{
	std::cout << nom << std::endl;
}

void Joueur::Jouer(Grille* grille)
{
}

Joueur::~Joueur()
{
}
