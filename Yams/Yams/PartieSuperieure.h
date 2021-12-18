//Valentin Lescorbie
//Nathan Hubert
#pragma once
#include "Figure.h"
#include <iostream>
#include <string>

template<int N>
class PartieSuperieure : public Figure //classe PartieSuperieur herite de la classe Figure et a un template int correspondant à la valeur du des choisi
{
public:
	PartieSuperieure();
	void calculScore();
};

template<int N>
inline PartieSuperieure<N>::PartieSuperieure(): Figure(("PartieSuperieur"+ std::to_string(N)))//constructeur PartieSuperieur appel constructeur de Figure avec le nom "PartieSuperieur" + numero du template X
{
}

template<int N>
inline void PartieSuperieure<N>::calculScore()
{
	int x = _result_lancer[N - 1];
	int res = x * N;
	_score = res;
}//on regarde dans le tableau d'occurence à la case correspondant pour la valeur de N pour calculé le score 