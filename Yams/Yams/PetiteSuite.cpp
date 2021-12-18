#include "PetiteSuite.h"
#include <algorithm>

PetiteSuite::PetiteSuite() : Figure( "PetiteSuite")//constructeur de PetiteSuite appel constructeur de Figure avec le nom "PetiteSuite"
{
}

void PetiteSuite::calculScore()
{
	int res = 0; 
	if (isFigure()) {
		res = 30;
	}
	_score = res;
}//si la figure est valide le score de la figure passe à 30 pts


bool PetiteSuite::isFigure()
{
	int cpt = 0;
	for (int dice : _result_lancer) {
		if (dice > 0) {
			cpt++;
		}
		else {
			cpt = 0;
		}
		if (cpt == 4) {
			return true;
		}
	}
	return false;
}//vérifie si un occurence est supérieur à 0 si c'est le cas alors le compteur s'incrémente si le compteur atteint 4 alors la figure est validé 
