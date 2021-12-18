#pragma once
#include "Dice.h"
#include <vector>

class Lancer {
	std::vector<Dice> _list_des;
	//un lancer ne possède qu'un tabelau de des
public:
	Lancer();
	void jet();
	void affiche();
	std::vector<Dice>& getDice();
	std::vector<int> getTabOccur();
	void resetDice();
};