#include <iostream>

class Grille
{
public:
  Grille();
  void ajouterPiece(int colonne, char couleur);
  void display();
  bool ColonnePleine(int colonne);

private:
  char grille[6][7];

};
