
//Nathan Hubert
//Valentin Lescorbie
#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Figure.h"

class Chance : public Figure{

public:
	Chance(std::vector<int> result_lancer);
	int calculScore();

};