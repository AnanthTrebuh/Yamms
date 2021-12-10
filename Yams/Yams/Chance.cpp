//Nathan Hubert
//Valentin Lescorbie

#include "Chance.h"
#include <vector>

Chance::Chance(std::vector<int> result_lancer): Figure(result_lancer, "Chance")
{
	_score = calculScore();
}

