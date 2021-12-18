//Nathan Hubert
//Valentin Lescorbie

#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "Figure.h"

class PetiteSuite : public Figure//classe PetiteSuite qui hérite de la Classe Figure
{
public:
	PetiteSuite();
	void calculScore();
	bool isFigure();
};