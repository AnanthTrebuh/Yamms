//Valentin Lescorbie
//Nathan Hubert

#pragma once
#include "Figure.h"


class GrandeSuite : public Figure
{
public :
	GrandeSuite(std::vector<int> lancer);
	int calculScore();
	bool isFigure();
};

