#include "Grille.h"

using namespace std;

Grille::Grille()
{
  for(int i=0;i<7;i++)
  {
    for(int j=0;j<8;j++)
    {
      grille[i][j]=' ';
    }
  }
}

void Grille::display()
{
  for(int i=6;i>=0;i--)
  {
    for(int j=0;j<8;j++)
    {
    cout<<"| " <<grille[i][j]<<' ';
    }
    cout << "|"<<'\n';
  }
}

void Grille::ajouterPiece(int colonne, char couleur)
{
  int i=5;
  while (grille[i][colonne]==' ' && i!=0) {
    i--;
  }

  grille[i][colonne]=couleur;
}

bool Grille::ColonnePleine(int colonne)
{
  char ligne = grille[5][colonne]; //Si la plus haute case est occupée alors la ligne est pleine
	if (ligne == 'O' || ligne == 'X')
	{
		return 1;
	}
	else
		return 0;
}
