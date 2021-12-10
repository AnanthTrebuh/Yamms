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
	Carre();
};


inline Carre::Carre() : SameDice<4>( "Carre")
{
}