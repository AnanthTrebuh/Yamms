#include "Yahtzee.h"

Yahtzee::Yahtzee() : SameDice <5>("Yahtzee")
{
}

int Yahtzee::calculScore()
{
	int res = 0;
	if (this->isFigure()) {
		res = 50;
	}
	_score = res;
	return res;
}
