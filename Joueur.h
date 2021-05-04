#include <iostream>
#include <string>
#include "Grille.h"

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
