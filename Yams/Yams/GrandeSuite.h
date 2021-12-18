//Valentin Lescorbie
//Nathan Hubert

#pragma once
#include "Figure.h"


class GrandeSuite : public Figure//classe GrandeSuite hérite de la classe Figure 
{
public :
	GrandeSuite();
	void calculScore();
	bool isFigure();
};

