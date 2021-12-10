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
	PartieSuperieure();
	int calculScore();
};

template<int N>
inline PartieSuperieure<N>::PartieSuperieure(): Figure(("PartieSuperieur"+ std::to_string(N)))
{
	_score = 0;
}

template<int N>
inline int PartieSuperieure<N>::calculScore()
{
	int x = _result_lancer[N - 1];
	int res = x * N;
	return res;
}