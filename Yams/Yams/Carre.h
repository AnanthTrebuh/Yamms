//Nathan Hubert
//Valentin Lescorbie

#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "SameDice.h"
#include <vector>

class Carre : public SameDice<4> {//Classe Carre herite de la classe SameDice 

public:
	Carre();
};

inline Carre::Carre() : SameDice<4>( "Carre") //constructeur Carre appele cosntructeur SameDice avec le chifre 4 pour les 4 des identique et le nom "Carre"
{
}