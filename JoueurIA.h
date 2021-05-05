#pragma once
#include "Joueur.h"

class JoueurIA :
	public Joueur
{
public:
	JoueurIA(std::string _nom, char _jeton);
	void Jouer(Grille* grille);
	~JoueurIA();

private:
	int Minimax(Grille* grille);
	int* tourMax(Grille* grille, int _noeud);
	int* tourMin(Grille* grille, int _noeud);
	int utilite(Grille* grille, std::string joueur);
	int action;
	int utility = -100;
	char jeton_adverse;
	int AlgoIA(Grille* grille);
	int noeud = 0;
	int niveau;
	int tabMin[2];
	int tabMax[2];
};
