// TP_Puissance4.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "Grille.h"
#include "JoueurHumain.h"
#include "JoueurIA.h"
#include "Puissance4.h"

int main()
{
	Puissance4	*jeu = new Puissance4("Jeu");
	jeu->demarrer();
	system("pause");
    return 0;
}
