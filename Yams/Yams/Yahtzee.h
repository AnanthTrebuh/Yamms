//Nathan Hubert
//Valentin Lescorbie
#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SameDice.h"


class Yahtzee : public SameDice<5> {//classe Yahtzee hérite de de la classe SameDice

public:
	Yahtzee();
	void calculScore();

};

