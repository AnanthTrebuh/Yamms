#pragma once
#include "Des.h"
#include <vector>

class Lancer {
	std::vector<Des> _list_des;
public:
	Lancer();
	void jet();
	void affiche();
	std::vector<Des>& getDice();
};