#include "Player.h"
#include "Carre.h"
#include "Chance.h"
#include "Full.h"
#include "Yahtzee.h"
#include "GrandeSuite.h"
#include "PetiteSuite.h"
#include "Brelan.h"
#include "PartieSuperieure.h"

Player::Player()
{
	_id = 0;
	_name = "None";
	_score = 0;
	_figures = std::vector<Figure>();
	_figureToDo = std::vector<Figure>();
	addFigureTodo();

	
	
}

Player::Player(int id, std::string name): _id(id), _name(name)
{
	_score = 0;
	_figures = std::vector<Figure>();
	_figureToDo = std::vector<Figure>();
	addFigureTodo();
}

Player::Player(const Player& p)
{
	_id = p._id;
	_name = p._name;
	_score = p._score;
	for (int i = 0; i < p._figures.size(); i++)
	{
		_figures.push_back(p._figures[i]);
	}
	for (int j = 0; j < p._figureToDo.size(); j++)
	{
		_figureToDo.push_back(p._figureToDo[j]);
	}
	_figureToDo = p._figureToDo;
}

Player& Player::operator=(Player& p)
{
	Player pl = Player(p);
	return pl;
}//peut être a revoir 

Player::~Player()
{
}

int Player::calculScore()
{
	int scr = 0;
	for (int i = 0; i < _figures.size(); i++)
	{
		scr += _figures.at(i).getScore();
	}
	_score = scr;
	return scr;
}

void Player::addFigure(Figure& fig, std::vector<int> dices)
{
	int valX = 0;
	int valY = 0;
	if (fig.getName() == "Full") {
		//faut caster mais je comprend pas comment faire sinon modifier le truc des calcul sera moins chiant
	}
	else if (fig.getName() == "Brelan", fig.getName() == "Carre", fig.getName() == "Yahtzee") {
		std::cout << "Quels est le des en plusieurs exemplaire dans votre combinaison ? ex : Brelan de 2, 3..." << std::endl;
		while (!(std::cin >> valX) || valX < 1 || valX >6) {
			std::cout << "La valeur ne correspond pas, elle doit etre entre 1 et 6, recommencer :";
			std::cin.clear(); // effacer les bits d'erreurs 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	for (int i = 0; i < _figureToDo.size(); i++)
	{
		if (fig.getName() == _figureToDo.at(i).getName()) {
			_figures.push_back(fig);
			_figureToDo.erase(_figureToDo.begin() + i);
		}
	}
	calculScore();
}

int Player::getScore()
{
	return _score;
}

void Player::addFigureTodo()
{
	std::vector<int> dices = { 0,0,0,0,0};
	PartieSuperieure<1> p1(dices);
	PartieSuperieure<2> p2(dices);
	PartieSuperieure<3> p3(dices);
	PartieSuperieure<4> p4(dices);
	PartieSuperieure<5> p5(dices);
	PartieSuperieure<6> p6(dices);
	Chance c(dices);
	Brelan b(dices);
	Yahtzee y(dices);
	Carre carre(dices);
	Full f(dices);
	PetiteSuite ps(dices);
	GrandeSuite gs(dices);
	_figureToDo.push_back(p1);
	_figureToDo.push_back(p2);
	_figureToDo.push_back(p3);
	_figureToDo.push_back(p4);
	_figureToDo.push_back(p5);
	_figureToDo.push_back(p6);
	_figureToDo.push_back(c);
	_figureToDo.push_back(b);
	_figureToDo.push_back(y);
	_figureToDo.push_back(carre);
	_figureToDo.push_back(f);
	_figureToDo.push_back(ps);
	_figureToDo.push_back(gs);

}

std::vector<Figure> Player::getFigureTodo()
{
	return _figureToDo;
}



std::string Player::getName()
{
	return _name;
}

void Player::afficheFigureToDo()
{
	int i = 0; 
	for (Figure fig : _figureToDo) {
		std::cout << i << " : " << fig.getName() << std::endl;
		i++;
	}
}

void Player::affichePlayer()
{
	std::cout << "Joueur no " << _id << " : " << _name << std::endl;
}
