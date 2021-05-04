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
  char **new_grille=grille.getGrille();

  for(int i=6;i>=0;i--)
  {
    for(int j=0;j<8;j++)
    {
    cout<<"| " <<new_grille[i][j]<<' ';
    }
    cout << "|"<<'\n';
  }

  return 0;
}
