#pragma once
#include "Jeu.h"
#include "Grille.h"
#include "JoueurHumain.h"
#include "JoueurIA.h"
#include "Joueur.h"

class Puissance4 : public Jeu
{
public:
	Puissance4(std::string _nom);
	~Puissance4();
	void	demarrer();

private:
	void	recommencer();

	Grille	*grille;

	Joueur	*joueur1;
	Joueur	*joueur2;
};

