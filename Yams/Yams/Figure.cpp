#include "Figure.h"
#include <vector>

Figure::Figure( std::string name) : _score(0), _name(name), _result_lancer({0,0,0,0,0,0})
{
}
//contructeur de la figure 
// Figure automatiquement créer avec un score de 0, le nom mis en paramètre et un tabelau d'occurence mis à 0 sur toute les valeurs

void Figure::calculScore() {
	int tot = 0;
	if (isFigure()) {
		for (int i = 0; i < _result_lancer.size(); i++)
		{
			tot += _result_lancer[i] * (i + 1);
		}
	}
	_score = tot;
}//on vérifie que la figure est bonne si c'est le cas on fait le calcule du score qui est ensuite mis dans l'attribut correspondant, sinon le score reste  le même à 0


bool Figure::isFigure()
{
	return true;
}//dans la class emère on considère que la figure est True;

int Figure::getScore()
{
	return _score;
}//renvoie le _score de la figrue 

std::string Figure::getName()
{
	return _name;
}//renvoie le nom de la figure 

void Figure::setDice(std::vector<int> dices)
{
	_result_lancer = dices;
	calculScore();
}// met le tabelau d'occurence dans la Figure pour ensuite lancer le calculScore pour que la figure soit complete.
