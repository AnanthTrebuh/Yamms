//Valentin Lescorbie
//Nathan Hubert
#include "GrandeSuite.h"
#include <algorithm>
#include <vector>

GrandeSuite::GrandeSuite() : Figure("GrandeSuite")//constructeur de GrandeSuite appel constructeur de Figure avec le nom "GrandeSuite"
{
}

void GrandeSuite::calculScore()
{
	int res = 0;
	if (isFigure()) {
		res = 40;
	}
	_score = res;
}//si la figure est valide le score de la figure passe � 40 pts

bool GrandeSuite::isFigure() {
	int cpt = 0;
	for (int dice : _result_lancer) {
		if (dice > 0) {
			cpt++;
		}
		else {
			cpt = 0;
		}
		if (cpt == 5) {
			return true;
		}
	}
	return false;
}//v�rifie si un occurence est sup�rieur � 0 si c'est le cas alors le compteur s'incr�mente si le compteur atteint 5 alors la figure est valid� 