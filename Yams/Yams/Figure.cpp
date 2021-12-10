#include "Figure.h"
#include <vector>

Figure::Figure( std::string name) : _score(0), _name(name), _result_lancer({0,0,0,0,0,0})
{
}

int Figure::calculScore() {
	int tot = 0;
	if (isFigure()) {
		for (int i = 0; i < _result_lancer.size(); i++)
		{
			tot += _result_lancer[i] * (i + 1);
		}
		_score = tot;
	}
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
	/*for (int val : dices) {
		_result_lancer.push_back(val);
	}*/
	_result_lancer = dices;
	calculScore();
}
