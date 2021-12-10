#pragma once
#include "Dice.h"
#include <vector>

class Lancer {
	std::vector<Dice> _list_des;
public:
	Lancer();
	void jet();
	void affiche();
	std::vector<Dice>& getDice();
	void resetDice();
};