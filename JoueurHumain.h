#pragma once
#include "Joueur.h"
class JoueurHumain :
	public Joueur
{
public:
	JoueurHumain(std::string _nom, char _jeton);
	int ChoixColonne(Grille* grille);
	void Jouer(Grille* grille);
	~JoueurHumain();
};
