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
  for(int i=0;i<7;i++)
  {
    for(int j=0;j<8;j++)
    {
    cout<<"| " <<grille[i][j];
    }
    cout << "|"<<'\n';
  }
}
