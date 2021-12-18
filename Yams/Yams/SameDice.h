//Nathan Hubert
//Valentin Lescorbie

#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "Figure.h"

template<int X>
class SameDice : public Figure {//Classe SameDice h�rite del a classe Figure 
public:
	SameDice(std::string name);
	bool isFigure();
};

template<int X>
inline SameDice<X>::SameDice(std::string name) : Figure(name) //construicteur de Samedice appel le constructeur de Figure avec le nom pass� en param�tre 
{
}



template<int X>
inline bool SameDice<X>::isFigure()//pour v�rifi� si la figure est valide on regarde dans le tabelau d'occurence si une des occurence est �gale � la valeur du template X 
//3 pour le Brelan, 4 pour le carre et 5 pour le Yahtzee
{
	bool res = false; 
	for (int i = 0; i < _result_lancer.size(); i++) {
		if (_result_lancer[i] >= X) {
			res = true;
		}
	}
	return res;
}