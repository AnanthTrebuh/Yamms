#pragma once
#include "Des.h"
#include <vector>

class Lancer {
	std::vector<Des> _list_des;
public:
	Lancer();
	void jet();
	void jet(std::vector<int> nb_lancer);
	void affiche();
	std::vector<Des> getDice();
};