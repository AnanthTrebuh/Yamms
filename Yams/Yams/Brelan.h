#pragma once
//Nathan Hubert
//Valentin Lescorbie

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SameDice.h"

template<int X>
class Brelan : public SameDice<X, 3> {

public:
	Brelan(std::vector<int> result_lancer);
};

template<int X>
inline Brelan<X>::Brelan(std::vector<int> result_lancer) : SameDice<X, 3>(result_lancer, "Brelan")
{

}