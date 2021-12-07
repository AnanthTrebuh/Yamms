#include "Figure.h"
#include <vector>

Figure::Figure(std::vector<int> result_lancer, std::string name) : _score(0)
{
	for (int i = 0; i < 5; i++) {
		_result_lancer.push_back(result_lancer[i]);
	}
}

bool Figure::isFigure()
{
	return true;
}

int Figure::getScore()
{
	return _score;
}
