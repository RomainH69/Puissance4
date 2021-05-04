#include <iostream>
#include "Grille.h"

using namespace std;

int main()
{
  cout<<"Hi"<<endl;

  Grille grille;
  grille.display();
  grille.ajouterPiece(4, 'X');
  //grille.display();
  

  return 0;
}
