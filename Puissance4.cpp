
#include "Puissance4.h"

using namespace std;

Puissance4::Puissance4(std::string _nom) :Jeu(_nom)
{
	cout << "Puissance 4" << endl;

	int choix = -1;
	while (choix <0 || choix > 2)
	{
		cout << "Nouvelle Partie : contre l'ia (tapez 0) multijoueur (tapez 1) Ia vs Ia (tapez 2)" << endl;
		cout << "choix : ";
		cin >> choix;
	}


	if (choix == 0)
	{
		singlePlayer = true;

		joueur1 = new JoueurHumain("Jean", 'X');
		joueur2 = new JoueurIA("Paul",'O');
	}
	else if(choix == 1)
	{
		singlePlayer = false;
		joueur1 = new JoueurHumain("Jean", 'X');
		joueur2 = new JoueurHumain("Pierre",'O');
	}
	else if (choix == 2)
	{
		joueur1 = new JoueurIA("Pierre", 'X');
		joueur2 = new JoueurIA("Paul", 'O');
	}
	grille = new Grille();
}


Puissance4::~Puissance4()
{

}

void	Puissance4::demarrer()
{
	int a = 0;
	grille->Afficher();
	while (grille->Gagne()=='N' && a<42)
	{
		if (a % 2 == 0)
		{
			joueur1->Jouer(grille);
		}
		else
		{
			joueur2->Jouer(grille);
		}
		a++;
	}
	grille->Afficher();
	if(grille->Gagne() != 'N')
		std::cout << "Nous avons un gagnant !" << std::endl;
	else
		std::cout << "Plus de jetons" << std::endl;

	std::cout << "Entrez 1 pour recommencer" << std::endl;
	cin >> a;
	if (a)
		recommencer();
}

void	Puissance4::recommencer()
{
	joueur1 = new JoueurHumain("Truc", 'X');

	if (singlePlayer == true)
		joueur2 = new JoueurIA("Machin", 'O');
	else
		joueur2 = new JoueurHumain("Chose", 'O');


	grille->Initialiser();
	Puissance4("jeu");
	demarrer();
}
