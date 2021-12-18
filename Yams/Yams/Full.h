//Nathan Hubert
//Valentin Lescorbie

#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "Figure.h"

class Full : public Figure {//classe Full h�rite de Figure 
public:
	Full();
	void calculScore();
	bool isFigure();
};

inline Full::Full() : Figure("Full")//constructeur de Full appel le constructeur de Figure avec le nom "Full"
{
}

inline void Full::calculScore()
{
	unsigned int res = 0;
	if (isFigure()){
		res = 25; 
	}
	_score = res;
}//v�rifie si la figure est valide et met le score de 25 pts

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
}//v�rifi� si un des �l�ment du tabelau d'occurence est �gale � 2 et si un est �gale � 3, si c'est le cas alors la figure est valide.
