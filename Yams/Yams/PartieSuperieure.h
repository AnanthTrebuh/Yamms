//Valentin Lescorbie
//Nathan Hubert
#pragma once
#include "Figure.h"
#include <iostream>
#include <string>

template<int N>
class PartieSuperieure : public Figure
{
public:
	PartieSuperieure(std::vector<int> lancer);
	int calculScore();
};

template<int n>
inline PartieSuperieure<n>::PartieSuperieure(std::vector<int>  lancer): Figure(lancer, ("PartieSuperieur"+ std::to_string(n)))
{
	_score = calculScore();
}

template<int N>
inline int PartieSuperieure<N>::calculScore()
{
	int nb = 0;
	for (unsigned int i = 0; i < _result_lancer.size(); i++)
	{
		if (_result_lancer[i] == N) {
			nb++;
		}
	}
	int res = N * nb;
	return res;
}