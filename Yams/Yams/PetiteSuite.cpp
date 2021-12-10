#include "PetiteSuite.h"
#include <algorithm>

PetiteSuite::PetiteSuite() : Figure( "PetiteSuite")
{
}

int PetiteSuite::calculScore()
{
	int res = 0; 
	if (isFigure()) {
		res = 30;
	}
	_score = res;
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
