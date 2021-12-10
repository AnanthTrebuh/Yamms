#include "PetiteSuite.h"
#include <algorithm>

PetiteSuite::PetiteSuite() : Figure( "PetiteSuite")
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
	int cpt = 0;
	for (int dice : _result_lancer) {
		if (dice > 0) {
			cpt++;
		}
		else {
			cpt = 0;
		}
		if (cpt == 4) {
			return true;
		}
	}
	return false;
}
