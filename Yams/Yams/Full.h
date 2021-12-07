//Nathan Hubert
//Valentin Lescorbie

#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "Figure.h"

template<int X, int Y>
class Full : public Figure {

public:
	Full(std::vector<int> result_lancer);
	int calculScore();
	bool isFigure();

};

template<int X, int Y>
inline Full<X, Y>::Full(std::vector<int> result_lancer) : Figure(result_lancer, "Full")
{
	_score = calculScore();
}

template<int X, int Y>
inline int Full<X, Y>::calculScore()
{
	unsigned int res = 0;
	if (isFigure()){
		res = 25; 
	}
	return res;
}

template<int X, int Y>
inline bool Full<X, Y>::isFigure()
{
	int cptX =0, cptY = 0;
	for (int elem : _result_lancer) {
		if (elem == X) {
			cptX++;
		}
		if (elem == Y) {
			cptY++;
		}
	}
	return  (cptX == 3 && cptY == 2 || cptX == 2 && cptY == 3);
	
}
