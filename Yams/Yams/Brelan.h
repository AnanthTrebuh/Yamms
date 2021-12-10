#pragma once
//Nathan Hubert
//Valentin Lescorbie

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SameDice.h"

class Brelan : public SameDice<3> {

public:
	Brelan();
};

inline Brelan::Brelan() : SameDice<3>("Brelan")
{

}