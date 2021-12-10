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
	bool res = false;
	for (int elem : _result_lancer) {
		if (elem == 1) {
			res = true;
		}
		else {
			return false;
		}
	}
	return res;
}