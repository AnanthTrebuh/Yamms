//Nathan Hubert
//Valentin Lescorbie

#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "Figure.h"

class PetiteSuite : public Figure
{
public:
	PetiteSuite(std::vector<int> result_lancer);
	int calculScore();
	bool isFigure();
};