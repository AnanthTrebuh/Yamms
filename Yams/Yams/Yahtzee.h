//Nathan Hubert
//Valentin Lescorbie
#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SameDice.h"


class Yahtzee : public SameDice<5> {

public:
	Yahtzee();
	int calculScore();

};

inline Yahtzee::Yahtzee() : SameDice <5>( "Yahtzee")
{
}

inline int Yahtzee::calculScore()
{
	int res = 0;
	if (this->isFigure()){
		res = 50;
	}
	_score = res;
	return res;
}
