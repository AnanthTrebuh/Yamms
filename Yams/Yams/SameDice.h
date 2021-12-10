//Nathan Hubert
//Valentin Lescorbie

#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "Figure.h"

template<int X>
class SameDice : public Figure {
public:
	SameDice(std::string name);
	int calculScore();
	bool isFigure();
};

template<int X>
inline SameDice<X>::SameDice(std::string name) : Figure(name)
{
	_score = calculScore();
}

template<int X>
inline int SameDice<X>::calculScore()
{
	int res = 0;
	if (isFigure()) {
		int res = 0;
		for (int i = 0; i < _result_lancer.size(); i++) {
			res += _result_lancer[i] *(i+1);
		}
		_score = res; 
	}
	return res;
}

template<int X>
inline bool SameDice<X>::isFigure()
{
	bool res = false; 
	for (int d : _result_lancer) {
		if (d == X) {
			res = true;
		}
	}
	return res;
}