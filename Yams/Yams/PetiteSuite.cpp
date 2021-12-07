#include "PetiteSuite.h"
#include <algorithm>

PetiteSuite::PetiteSuite(std::vector<int> result_lancer) : Figure(result_lancer, "PetiteSuite")
{
	_score = calculScore();
}

int PetiteSuite::calculScore()
{
	int res = 0; 
	if (isFigure()) {
		res = 30;
	}
	return res;
}


bool PetiteSuite::isFigure()
{
	int cpt = 1;
	int elemPrec = _result_lancer[0];
	std::sort(_result_lancer.begin(), _result_lancer.end());
	for (unsigned int i = 1; i < _result_lancer.size(); i++) {
		if (_result_lancer[i] == elemPrec + 1) {
			cpt++;
			elemPrec++;
		}
		else if (_result_lancer[i] == elemPrec) {
		}else {
			elemPrec = _result_lancer[i];
			cpt = 1;
		}
		if (cpt == 4) break;
	}
	return (cpt == 4);
}
