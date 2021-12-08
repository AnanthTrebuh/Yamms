#include "Lancer.h"

Lancer::Lancer()//creation de la classe lancer avec 5 des 
{
	for (int i = 0; i < 5; i++) {
		Des d = Des(i + 1);
		_list_des.push_back(d);
	}
	/*Des d1(1);
	Des d2(2);
	Des d3(3);
	Des d4(4);
	Des d5(5);
	_list_des.push_back(d1);
	_list_des.push_back(d2);
	_list_des.push_back(d3);
	_list_des.push_back(d4);
	_list_des.push_back(d5);*/


}

void Lancer::jet()
{
	int i = 0;
	for (Des elem : _list_des) {
		_list_des[i].jet();
		i++;
	}
	/*for (int i = 0; i < _list_des.size(); i++) {
		_list_des[i].jet();
	}*/
}

void Lancer::jet(std::vector<int> nb_lancer)
{
	for (int elem : nb_lancer) {
		_list_des[elem - 1].jet();
	}
}

void Lancer::affiche()
{
	for (Des elem : _list_des) {
		elem.affiche();
	}
}

std::vector<Des> Lancer::getDice()
{
	return _list_des;
}
