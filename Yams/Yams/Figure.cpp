#include "Figure.h"
#include <vector>

Figure::Figure(std::vector<int> result_lancer, std::string name) : _score(0), _name(name)
{
	for (int i = 0; i < 5; i++) {
		_result_lancer.push_back(result_lancer[i]);
	}
}

int Figure::calculScore() {
	int tot = 0;
	for (int i = 0; i < _result_lancer.size(); i++)
	{
		tot += _result_lancer[i];
	}
	_score = tot;
	return tot;
}


bool Figure::isFigure()
{
	return true;
}

int Figure::getScore()
{
	return _score;
}

std::string Figure::getName()
{
	return _name;
}

void Figure::setDice(std::vector<int> dices)
{
	for (int val : dices) {
		_result_lancer.push_back(val);
	}
}
