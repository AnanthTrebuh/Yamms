//Nathan Hubert
//Valentin Lescorbie
#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SameDice.h"


class Yahtzee : public SameDice< 5> {

public:
	Yahtzee(std::vector<int> result_lancer, int value);
	int calculScore();

};

inline Yahtzee::Yahtzee(std::vector<int> result_lancer, int value) : SameDice <5>(result_lancer, "Yahtzee", value)
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
