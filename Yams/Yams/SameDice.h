//Nathan Hubert
//Valentin Lescorbie

#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "Figure.h"

template<int X, int Y>
class SameDice : public Figure {

public:
	SameDice(std::vector<int> result_lancer, std::string name);
	int calculScore();
	bool isFigure();

};

template<int X, int Y>
inline SameDice<X, Y>::SameDice(std::vector<int> result_lancer, std::string name) : Figure(result_lancer, name)
{
	_score = calculScore();
}

template<int X,int Y>
inline int SameDice<X,Y>::calculScore()
{
	if (isFigure()) {
		int res = 0;
		for (int elem : _result_lancer) {
			res += elem;
		}
		return res;
	}
	else {
		return 0;
	}
}

template<int X, int Y>
inline bool SameDice<X, Y>::isFigure()
{
	int cpt = 0;
	for (int elem : _result_lancer) {
		if (elem == X) {
			cpt++;
		}
	}
	return(cpt >= Y);
}
