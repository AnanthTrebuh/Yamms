#include "Lancer.h"
#include <iostream>

Lancer::Lancer()//creation de la classe lancer avec 5 des 
{
	for (int i = 0; i < 5; i++) {
		Des d = Des(i + 1);
		_list_des.push_back(d);
	}
}

void Lancer::jet()
{
	for (int i = 0; i < _list_des.size(); i++) {
		if (!(_list_des[i].isKeep())) {
			_list_des[i].jet();
		}
	}
}

void Lancer::affiche() {
	std::cout << " _____  _____  _____  _____  _____ " << std::endl;

	for(int i = 0; i < 3; i++){
		for (Des elem : _list_des) {
			switch (i) {
			case 0: switch (elem.getValeur())
					{
					case 1: std::cout << "|     |";  break;
					case 2:
					case 3:std::cout << "|O    |"; break;
					case 4: 
					case 5:
					case 6:std::cout << "|O   O|"; break;
					default:
						break;
			} break;
			case 1: switch (elem.getValeur()) {
					case 1: 
					case 3:
					case 5:std::cout << "|  O  |"; break;
					case 4:
					case 2:std::cout << "|     |"; break;
					case 6:std::cout << "|O   O|"; break;
					default:
						break;
					}break;
			case 2: switch (elem.getValeur()) {
					case 1: std::cout << "|_____|";  break;
					case 2:
					case 3: std::cout << "|____O|"; break;
					case 4:
					case 5:
					case 6:std::cout << "|O___O|"; break;
					default:
						break;
					}
				break;
			}
		}
		std::cout << std::endl;
	}
}
std::vector<Des> Lancer::getDice()
{
	return _list_des;
}
