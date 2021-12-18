#pragma once
//Nathan Hubert
//Valentin Lescorbie

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SameDice.h"

class Brelan : public SameDice<3> { //Classe Brelan herite de la classe sameDice

public:
	Brelan();
};

inline Brelan::Brelan() : SameDice<3>("Brelan") //constructeur Brelan appele cosntructeur Same Dice avec le chifre 3 pour les 3 des identique et le nom "Brelan"
{

}