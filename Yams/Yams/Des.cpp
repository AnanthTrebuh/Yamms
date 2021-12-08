#include "Des.h"
#include <stdlib.h> 
#include <iostream>

Des::Des()
{
	_id = 0;
	_valeur = 0;
}

Des::Des(int id):_id(id)
{
	_valeur = 0;
}

Des::Des(const Des& d)
{
	_id = d._id;
	_valeur = d._valeur;
}

Des& Des::operator=(Des& d)
{
	Des newD = Des(d);
	return newD;
}

Des::~Des()
{
}

int Des::jet()
{
	_valeur = (rand() % 6) + 1;
	return _valeur;
}

int Des::getId()
{
	return _id;
}

int Des::getValeur()
{
	return _valeur;
}

bool Des::isKeep()
{
	return _keep;
}

void Des::setKeep(bool keep)
{
	_keep = keep;
}

void Des::affiche()
{
	switch (_valeur) {
	case 1: affiche1(); break;
	case 2: affiche2(); break;
	case 3: affiche3(); break;
	case 4: affiche4(); break;
	case 5: affiche5(); break;
	case 6: affiche6(); break;
	default: break;
	}
}

void Des::affiche1()
{
	std::cout << " _____" << std::endl;
	std::cout << "|     |" << std::endl;
	std::cout << "|  O  |" << std::endl;
	std::cout << "|_____|" << std::endl;
}

void Des::affiche2()
{
	std::cout << " _____" << std::endl;
	std::cout << "|O    |" << std::endl;
	std::cout << "|     |" << std::endl;
	std::cout << "|____O|" << std::endl;
}

void Des::affiche3()
{
	std::cout << " _____" << std::endl;
	std::cout << "|O    |" << std::endl;
	std::cout << "|  O  |" << std::endl;
	std::cout << "|____O|" << std::endl;
}

void Des::affiche4()
{
	std::cout << " _____" << std::endl;
	std::cout << "|O   O|" << std::endl;
	std::cout << "|     |" << std::endl;
	std::cout << "|O___O|" << std::endl;
}

void Des::affiche5()
{
	std::cout << " _____" << std::endl;
	std::cout << "|O   O|" << std::endl;
	std::cout << "|  O  |" << std::endl;
	std::cout << "|O___O|" << std::endl;
}

void Des::affiche6()
{
	std::cout << " _____" << std::endl;
	std::cout << "|O   O|" << std::endl;
	std::cout << "|O   O|" << std::endl;
	std::cout << "|O___O|" << std::endl;
}

