#include "Dice.h"
#include <stdlib.h> 
#include <time.h>
#include <iostream>

Dice::Dice()
{
	_id = 0;
	_valeur = 0;
	_keep = false;
}

Dice::Dice(int id):_id(id)
{
	_valeur = 0;
	_keep = false;
}

Dice::Dice(const Dice& d)
{
	_id = d._id;
	_valeur = d._valeur;
	_keep = d._keep;
}

Dice& Dice::operator=(Dice& d)
{
	Dice newD = Dice(d);
	return newD;
}

Dice::~Dice()
{
}

int Dice::jet()
{
	srand(time(NULL));
	_valeur = (rand() % 6) + 1;
	return _valeur;
}

int Dice::getId()
{
	return _id;
}

int Dice::getValeur()
{
	return _valeur;
}

bool Dice::isKeep()
{
	return _keep;
}

void Dice::setKeep(bool keep)
{
	_keep = keep;
}

void Dice::affiche()
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

void Dice::affiche1()
{
	std::cout << " _____" << std::endl;
	std::cout << "|     |" << std::endl;
	std::cout << "|  O  |" << std::endl;
	std::cout << "|_____|" << std::endl;
}

void Dice::affiche2()
{
	std::cout << " _____" << std::endl;
	std::cout << "|O    |" << std::endl;
	std::cout << "|     |" << std::endl;
	std::cout << "|____O|" << std::endl;
}

void Dice::affiche3()
{
	std::cout << " _____" << std::endl;
	std::cout << "|O    |" << std::endl;
	std::cout << "|  O  |" << std::endl;
	std::cout << "|____O|" << std::endl;
}

void Dice::affiche4()
{
	std::cout << " _____" << std::endl;
	std::cout << "|O   O|" << std::endl;
	std::cout << "|     |" << std::endl;
	std::cout << "|O___O|" << std::endl;
}

void Dice::affiche5()
{
	std::cout << " _____" << std::endl;
	std::cout << "|O   O|" << std::endl;
	std::cout << "|  O  |" << std::endl;
	std::cout << "|O___O|" << std::endl;
}

void Dice::affiche6()
{
	std::cout << " _____" << std::endl;
	std::cout << "|O   O|" << std::endl;
	std::cout << "|O   O|" << std::endl;
	std::cout << "|O___O|" << std::endl;
}

