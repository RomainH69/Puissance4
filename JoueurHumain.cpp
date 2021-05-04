#include "JoueurHumain.h"


JoueurHumain::JoueurHumain(std::string _nom, char _jeton) : Joueur(_nom, _jeton)
{
}

int JoueurHumain::ChoixColonne(Grille* grille)
{
	int colonne=-1;
	while (colonne < 0 || colonne>7) //Tant que l'utilisateur n'entre pas une colonne correcte
	{
		std::cout << "Entrez le numero de la colonne" << std::endl;
		std::cin >> colonne;
		colonne--;
		if (grille->ColonnePleine(colonne))
		{
			std::cout << "Colonne pleine" << std::endl; //Si colonne pleine, considerée comme invalide
			colonne = -1;
		}
	}

	return colonne;
}

void JoueurHumain::Jouer(Grille *grille)
{
	int colonne = ChoixColonne(grille);
	grille->ajouterPiece(colonne, jeton);
  grille->display();
}
