
#include "Grille.h"
#include "JoueurHumain.h"
#include "JoueurIA.h"

Grille::Grille()
{
	Initialiser();
	for (int i = 0; i < 4; i++)
	{
		tab[i] = new char;
	}
}

Grille::Grille(Grille const& grilleCopie) : ligne(grilleCopie.ligne), colonne(grilleCopie.colonne)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			grille[i][j] = grilleCopie.grille[i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		tab[i] = grilleCopie.tab[i];
	}

}


void Grille::Afficher()
{
	std::cout << "  1   2   3   4   5   6   7 " << std::endl;
	for (int i = 5; i >= 0; i--)
	{
		std::cout << "+---+---+---+---+---+---+---+" << std::endl;

		for (int j = 0; j <7; j++)
		{
			std::cout << "| ";
			if (&grille[i][j] == tab[0] || &grille[i][j] == tab[1] || &grille[i][j] == tab[2] || &grille[i][j] == tab[3])
			{
				std::cout << grille[i][j] << " ";
			}
			else
			{
				if (grille[i][j] == 'O')
				{
					std::cout << grille[i][j] << " ";
				}
				else if (grille[i][j] == 'X')
				{
					std::cout << grille[i][j] << " ";
				}
				else
					std::cout << grille[i][j] << " ";
			}


		}
		std::cout << "|" << std::endl;
	}
	std::cout << "+---+---+---+---+---+---+---+" << std::endl;
	std::cout << "  1   2   3   4   5   6   7 " << std::endl;


}
void Grille::Initialiser()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			grille[i][j] = ' ';
		}
	}
}

void Grille::AjouterJeton(int _colonne, char _jeton)
{
	int i;
	colonne = _colonne;
	for (i = 0; i < 6; i++)
	{
		if (grille[i][colonne] == ' ')
		{
			grille[i][colonne] = _jeton;
			ligne = i;
			break;
		}

	}
}
void Grille::Afficher_choix(int _colonne, char _jeton)
{
	AjouterJeton(_colonne, _jeton);
	Afficher();
	std::cout << "Jeton ajoute dans la colonne " << colonne+1 << std::endl;

}

bool Grille::ColonnePleine(int colonne)
{
	char ligne = grille[5][colonne];
	if (ligne == 'O' || ligne == 'X')
	{
		return 1;
	}
	else
		return 0;
}

char Grille::Gagne()
{
	bool gagne = false;
	int count = 1;
	int j = colonne - 1;
	char typeJeton = grille[ligne][colonne];
	char precedent = grille[ligne][colonne];
	tab[0] = &grille[ligne][colonne];
	if (typeJeton != ' ')
	{
		int a = 1;
		for (int i = ligne+1; i < 6; i++)
		{
			if (grille[i][colonne] == precedent)
			{
				precedent = grille[i][colonne];
				count++;
				tab[a] = &grille[i][colonne];
				a++;
			}
			else
			{
				precedent =grille[i][colonne];
				break;
			}

		}
		precedent = grille[ligne][colonne];
		for (int i = ligne -1; i >=0; i--)
		{
			if (grille[i][colonne] == precedent)
			{
				precedent = grille[i][colonne];
				count++;
				tab[a] = &grille[i][colonne];
				a++;
			}
			else
			{
				precedent = grille[i][colonne];
				break;
			}
		}

		if (count >= 4)
		{
			gagne = true;
		}

		else
		{
			count = 1;
			precedent = grille[ligne][colonne];
			int a = 1;
			for (int i = colonne + 1; i < 7; i++)
			{
				if (grille[ligne][i] == precedent)
				{
					precedent = grille[ligne][i];
					count++;
					tab[a] = &grille[ligne][i];
					a++;
				}
				else
				{
					precedent = grille[ligne][i];
					break;
				}
			}
			precedent = grille[ligne][colonne];
			for (int i = colonne - 1; i >= 0; i--)
			{
				if (grille[ligne][i] == precedent)
				{
					precedent = grille[ligne][i];
					count++;
					tab[a] = &grille[ligne][i];
					a++;
				}
				else
				{
					precedent = grille[ligne][i];
					break;
				}
			}

			if (count >= 4)
			{
				gagne = true;
			}

			else
			{
				count = 1;
				precedent = grille[ligne][colonne];
				int a = 1;
				int j = colonne - 1;
				for (int i = ligne + 1; i < 6 && j>=0; i++)
				{
					if (grille[i][j] == precedent)
					{
						precedent = grille[i][j];
						count++;
						tab[a] = &grille[i][j];
						a++;
					}
					else
					{
						precedent = grille[i][j];
						break;
					}
					j--;
				}
				precedent = grille[ligne][colonne];
				j = colonne + 1;
				for (int i = ligne - 1; i >= 0 && j<7; i--)
				{
					if (grille[i][j] == precedent)
					{
						precedent = grille[i][j];
						count++;
						tab[a] = &grille[i][j];
						a++;
					}
					else
					{
						precedent = grille[i][j];
						break;
					}
					j++;
				}

				if (count >= 4)
				{
					gagne = true;
				}

				else
				{
					count = 1;
					precedent = grille[ligne][colonne];
					j = colonne + 1;
					int a = 1;
					for (int i = ligne + 1; i < 6, j<7; i++)
					{
						if (grille[i][j] == precedent)
						{
							precedent = grille[i][j];
							count++;
							tab[a] = &grille[i][j];
							a++;
						}
						else
						{
							precedent = grille[i][j];
							break;
						}
						j++;
					}
					precedent = grille[ligne][colonne];
					j = colonne - 1;
					for (int i = ligne - 1; i >= 0, j>=0; i--)
					{
						if (grille[i][j] == precedent)
						{
							precedent = grille[i][j];
							count++;
							tab[a] = &grille[i][j];
							a++;
						}
						else
						{
							precedent = grille[i][j];
							break;
						}
						j--;
					}

					if (count >= 4)
					{
						gagne = true;
					}

					else
					{
						for (int i = 0; i < 5; i++)
						{
							tab[i] = NULL;
						}
					}
				}
			}
		}

	}
	if (gagne)
		return typeJeton;
	else
		return 'N';

}


Grille::~Grille()
{
}
