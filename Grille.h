#include <iostream>

class Grille
{
public:
  Grille();
  void ajouterPiece(int colonne, char couleur);
  char** getGrille();
  void display();

private:
  char grille[6][7];

};
