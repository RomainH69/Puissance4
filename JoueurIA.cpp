
#include "JoueurIA.h"


JoueurIA::JoueurIA(std ::string _nom, char _jeton) :Joueur(_nom, _jeton)
{
	if (_jeton == 'X')
		jeton_adverse = 'O';
	else
		jeton_adverse = 'X';
}

void JoueurIA::Jouer(Grille* grille)
{
	Grille* grille_temp = new Grille(*(grille));
	int colonne = Minimax(grille_temp);
	grille->Afficher_choix(colonne, jeton);
}

int JoueurIA::Minimax(Grille* grille)
{
	std::cout << "IA en reflexion ..." << std::endl;
	noeud = 0;
	int *tab_minimax(0);
	tab_minimax=tourMax(grille, noeud);
	return tab_minimax[1];
}

int* JoueurIA::tourMax(Grille* grille, int _noeud)
{
	int *tabMax= new int[2];
	int* tabMin;
	if (grille->Gagne() == 'N' && _noeud<7)
	{
		int u = -10000;
		int a =-1;
		for (int i = 0; i < 7; i++)
		{
			if (!grille->ColonnePleine(i))
			{
				Grille* newGrille = new Grille(*(grille));
				newGrille->AjouterJeton(i, jeton);
				if (newGrille->Gagne() == jeton_adverse)
				{
					a = i;
					u = -1;
					break;
				}
				else
				{
					tabMin = tourMin(newGrille, _noeud+1);
					if (tabMin[0] > u )
					{
						u = tabMin[0];
						a = i;
					}
				}


			}
		}
		tabMax[0]=u;
		tabMax[1] = a;
	}

	else
	{
		tabMax[0] =utilite(grille, "Max");
		tabMax[1] = -1;
	}

	return tabMax;
}

int* JoueurIA::tourMin(Grille* grille,int _noeud)
{
	int *tabMin= new int[2];
	int* tabMax;
	if (grille->Gagne() == 'N' && _noeud<7)
	{
		int u = 10000;
		int a=-1;
		for (int i = 0; i < 7; i++)
		{
			if (!grille->ColonnePleine(i))
			{
				Grille* newGrille = new Grille(*(grille));
				newGrille->AjouterJeton(i, jeton_adverse);
				if (newGrille->Gagne() == jeton)
				{
					a = i;
					u = 1;
					break;
				}
				else
				{
					tabMax = tourMax(newGrille, _noeud + 1);
					if (tabMax[0] < u)
					{
						u = tabMax[0];
						a = i;
					}
				}


			}
		}
		tabMin[0] =u;
		tabMin[1] = a;
	}

	else
	{
		tabMin[0] = utilite(grille, "Min");
		tabMin[1] = -1;
	}
	return tabMin;

}

int JoueurIA::utilite(Grille* grille, std::string joueur)
{
	int utilite = 0;

	if (joueur == "Max")
	{
		if (grille->Gagne() == jeton)
			utilite = 1;
		else if (grille->Gagne() == 'N')
				utilite = 0;
		else if (grille->Gagne() == jeton_adverse)
			utilite = -1;
	}
	else if (joueur == "Min")
	{
		if (grille->Gagne() == jeton_adverse)
			utilite = 1;
		else if (grille->Gagne() == 'N')
			utilite = 0;
		else if(grille->Gagne() == jeton)
			utilite = -1;
	}


	return utilite;
}
JoueurIA::~JoueurIA()
{
}
