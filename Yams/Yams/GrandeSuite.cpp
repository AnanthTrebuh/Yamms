//Valentin Lescorbie
//Nathan Hubert
#include "GrandeSuite.h"
#include <algorithm>
#include <vector>

GrandeSuite::GrandeSuite() : Figure("GrandeSuite")
{
}

int GrandeSuite::calculScore()
{
	int res = 0;
	if (isFigure()) {
		res = 40;
	}
	_score = res;
	return res;
}

bool GrandeSuite::isFigure() {
	int cpt = 0;
	for (int dice : _result_lancer) {
		if (dice > 0) {
			cpt++;
		}
		else {
			cpt = 0;
		}
		if (cpt == 5) {
			return true;
		}
	}
	return false;
}