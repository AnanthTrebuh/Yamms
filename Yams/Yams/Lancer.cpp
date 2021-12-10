#include "Lancer.h"
#include <iostream>
#include <chrono>
#include <thread>

Lancer::Lancer()//creation de la classe lancer avec 5 des 
{
	for (int i = 0; i < 5; i++) {
		Dice d = Dice(i + 1);
		_list_des.push_back(d);
	}
}

void Lancer::jet()
{
	std::cout << "Melange des Des..." << std::endl;
	for (int i = 0; i < _list_des.size(); i++) {
		if (!(_list_des[i].isKeep())) {
			_list_des[i].jet();
			//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
}

void Lancer::affiche() {
	std::cout << " _____  _____  _____  _____  _____ " << std::endl;

	for (int i = 0; i < 4; i++) {
		for (Dice elem : _list_des) {
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
			}break;
			case 3:
				if (elem.isKeep()) {
					std::cout << "   V   ";
				}
				else {
					std::cout << "   X   "; 
				}; 
				break;
			}
		}
		std::cout << std::endl;
	}
}

std::vector<Dice>& Lancer::getDice()
{
	return _list_des;
}

std::vector<int> Lancer::getTabOccur()
{
	std::vector<int> tab_occur = {0,0,0,0,0,0};
	unsigned int j = 0;
	for (int i = 0; i < 5; i++)
	{
		j = _list_des[i].getValeur() - 1;
		tab_occur[j]++;
	}
	return tab_occur;
}

void Lancer::resetDice() {
	for (int i = 0; i < _list_des.size(); i++)
	{
		_list_des[i].setKeep(false);
	}
}