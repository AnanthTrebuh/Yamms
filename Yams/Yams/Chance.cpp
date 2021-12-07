//Nathan Hubert
//Valentin Lescorbie

#include "Chance.h"
#include <vector>

Chance::Chance(std::vector<int> result_lancer): Figure(result_lancer, "Chance")
{
	_score = calculScore();
}

int Chance::calculScore()
{
	for (int elem : _result_lancer) {
		_score += elem;
	}
	return _score;
}