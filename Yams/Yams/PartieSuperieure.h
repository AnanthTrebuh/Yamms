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
	int x = _result_lancer[N - 1];
	int res = x * N;
	return res;
}