//Nathan Hubert
//Valentin Lescorbie
#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SameDice.h"


class Yahtzee : public SameDice<5> {

public:
	Yahtzee(std::vector<int> result_lancer);
	int calculScore();

};

inline Yahtzee::Yahtzee(std::vector<int> result_lancer) : SameDice <5>(result_lancer, "Yahtzee")
{
	Figure::_score = calculScore();
}

inline int Yahtzee::calculScore()
{
	int res = 0;
	if (this->isFigure()){
		res = 50;
	}
	return res;
}
