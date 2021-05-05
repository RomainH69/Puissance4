
#include "JoueurHumain.h"


JoueurHumain::JoueurHumain(std::string _nom, char _jeton) : Joueur(_nom, _jeton)
{
}

int JoueurHumain::ChoixColonne(Grille* grille)
{
	int colonne=-1;
	while (colonne < 0 || colonne>7)
	{
		std::cout << "Entrez le num�ro de la colonne" << std::endl;
		std::cin >> colonne;
		colonne--;
		if (grille->ColonnePleine(colonne))
		{
			std::cout << "Colonne pleine" << std::endl;
			colonne = -1;
		}
	}

	return colonne;
}

void JoueurHumain::Jouer(Grille *grille)
{
	int colonne = ChoixColonne(grille);
	grille->Afficher_choix(colonne, jeton);
}


JoueurHumain::~JoueurHumain()
{
}
