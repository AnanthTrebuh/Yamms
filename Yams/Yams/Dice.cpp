#include "Dice.h"
#include <stdlib.h> 
#include <time.h>
#include <iostream>

Dice::Dice()//constructeur de des par default
{
	_id = 0;
	_valeur = 0;
	_keep = false;
}

Dice::Dice(int id):_id(id)//constructeur avec un id en paramètre
{
	_valeur = 0;
	_keep = false;
}

Dice::Dice(const Dice& d)//constructeur de des par copie
{
	_id = d._id;
	_valeur = d._valeur;
	_keep = d._keep;
}

Dice& Dice::operator=(Dice& d)//redéfinition de l'opérateur égale
{
	Dice newD = Dice(d);
	return newD;
}

Dice::~Dice()//destrcuteur du des
{
}

int Dice::jet()//un jet de des qui va attribué une valeur aléatoire entre 1 et 6 au des et le mettre dans son attribut _valeur
{
	_valeur = (rand() % 6) + 1;
	return _valeur;
}

int Dice::getId()//renvoie l'id du des
{
	return _id;
}

int Dice::getValeur()//renvoie la valeur du des
{
	return _valeur;
}

bool Dice::isKeep()//renvoie le bool _keep du des
{
	return _keep;
}

void Dice::setKeep(bool keep)//applique un bool particulier à un des
{
	_keep = keep;
}