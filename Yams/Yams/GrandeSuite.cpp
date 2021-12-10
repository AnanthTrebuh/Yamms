//Valentin Lescorbie
//Nathan Hubert
#include "GrandeSuite.h"
#include <algorithm>
#include <vector>

GrandeSuite::GrandeSuite(std::vector<int> lancer) : Figure(lancer, "GrandeSuite")
{
	_score = calculScore();
}

int GrandeSuite::calculScore()
{
	int res = 0;
	if (isFigure()) {
		res = 40;
	}
	return res;
}

bool GrandeSuite::isFigure() {
	std::sort(_result_lancer.begin(), _result_lancer.end());
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