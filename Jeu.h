#pragma once

#include <iostream>
#include <string>

class Jeu
{
public:
	Jeu(std::string _nom);
	~Jeu();
	virtual void	demarrer() = 0;

protected:
	virtual void	recommencer() = 0;
	bool			singlePlayer;
	std::string nom;
};

