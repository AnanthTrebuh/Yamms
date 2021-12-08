//Nathan Hubert
//Valentin Lescorbie

#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SameDice.h"
#include <vector>

class Carre : public SameDice<4> {

public:
	Carre(std::vector<int> result_lancer, int value);
};


inline Carre::Carre(std::vector<int> result_lancer, int value) : SameDice<4>(result_lancer, "Carre", value)
{
}