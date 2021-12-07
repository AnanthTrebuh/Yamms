//Nathan Hubert
//Valentin Lescorbie
#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SameDice.h"

template <int X>
class Yahtzee : public SameDice<X, 5> {

public:
	Yahtzee(std::vector<int> result_lancer);
	int calculScore();

};

template<int X>
inline Yahtzee<X>::Yahtzee(std::vector<int> result_lancer) : SameDice < X,5>(result_lancer, "Yahtzee")
{
	Figure::_score = calculScore();
}

template<int N>
inline int Yahtzee<N>::calculScore()
{
	int res = 0;
	if (this->isFigure()){
		res = 50;
	}
	return res;
}
