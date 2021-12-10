//Nathan Hubert
//Valentin Lescorbie

#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "Figure.h"

class Full : public Figure {
public:
	Full(std::vector<int> result_lancer);
	int calculScore();
	bool isFigure();
};

inline Full::Full(std::vector<int> result_lancer) : Figure(result_lancer, "Full")
{
	_score = calculScore();
}

inline int Full::calculScore()
{
	unsigned int res = 0;
	if (isFigure()){
		res = 25; 
	}
	return res;
}

inline bool Full::isFigure()
{
	bool cptX = false , cptY = false;
	for (int elem : _result_lancer) {
		if (elem == 2) {
			cptX = true;
		}
		if (elem == 3){
			cptY = true;
		}
	}
	return  (cptX && cptY);
	
}
