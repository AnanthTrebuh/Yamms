#pragma once
//Nathan Hubert
//Valentin Lescorbie

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SameDice.h"

class Brelan : public SameDice<3> {

public:
	Brelan(std::vector<int> result_lancer, int value);
};

inline Brelan::Brelan(std::vector<int> result_lancer, int value) : SameDice<3>(result_lancer, "Brelan", value)
{

}