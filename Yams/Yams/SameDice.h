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
	int _value; 
public:
	SameDice(std::vector<int> result_lancer, std::string name, int value);
	int calculScore();
	bool isFigure();
	void setValue(int value); 
};

template<int X>
inline SameDice<X>::SameDice(std::vector<int> result_lancer, std::string name, int value) : Figure(result_lancer, name)
{
	_value = value;
	_score = calculScore();
}

template<int X>
inline int SameDice<X>::calculScore()
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

template<int X>
inline bool SameDice<X>::isFigure()
{
	int cpt = 0;
	for (int elem : _result_lancer) {
		if (elem == _value) {
			cpt++;
		}
	}
	return(cpt >= X);
}

template<int X>
inline void SameDice<X>::setValue(int value)
{
	_value = value;
}
