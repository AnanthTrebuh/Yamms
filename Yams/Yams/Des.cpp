#include "Des.h"
#include <stdlib.h> 

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

void Des::affiche()
{

}

