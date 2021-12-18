#include "Yahtzee.h"

Yahtzee::Yahtzee() : SameDice <5>("Yahtzee")//Constructeur de Yahtzee appel le constructeur de SameDice avec le Nom "Yahtzee" et le chiffre 5 pour le template
{
}

void Yahtzee::calculScore()
{
	int res = 0;
	if (this->isFigure()) {
		res = 50;
	}
	_score = res;
}
