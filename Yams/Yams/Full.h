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
	int _valueX;
	int _valueY;
public:
	Full(std::vector<int> result_lancer, int valueX, int valueY);
	int calculScore();
	bool isFigure();
	void setValues(int x, int y);

};

inline Full::Full(std::vector<int> result_lancer, int valueX, int valueY) : Figure(result_lancer, "Full")
{
	_valueX = valueX;
	_valueY = valueY;
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
	int cptX =0, cptY = 0;
	for (int elem : _result_lancer) {
		if (elem == _valueX) {
			cptX++;
		}
		if (elem == _valueY) {
			cptY++;
		}
	}
	return  (cptX == 3 && cptY == 2 || cptX == 2 && cptY == 3);
	
}

inline void Full::setValues(int x, int y)
{
	_valueX = x;
	_valueY = y;
}
