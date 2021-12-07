//Nathan Hubert
//Valentin Lescorbie

#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SameDice.h"
#include <vector>

template<int X>
class Carre : public SameDice<X,4> {

public:
	Carre(std::vector<int> result_lancer);
	/*int calculScore();
	bool isFigure();*/

};


template<int X>
inline Carre<X>::Carre(std::vector<int> result_lancer) : SameDice<X, 4>(result_lancer, "Carre")
{
}