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
}

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

void Player::addFigure(int i, std::vector<int> dices)
{
	_figureToDo[i].setDice(dices);
	//_figureToDo[i].calculScore();
	_figures.push_back(_figureToDo[i]);
	_figureToDo.erase(_figureToDo.begin() + i);
}

int Player::getScore()
{
	return _score;
}

void Player::addFigureTodo()
{
	PartieSuperieure<1> p1;
	PartieSuperieure<2> p2;
	PartieSuperieure<3> p3;
	PartieSuperieure<4> p4;
	PartieSuperieure<5> p5;
	PartieSuperieure<6> p6;
	Chance c;
	Brelan b;
	Yahtzee y;
	Carre carre;
	Full f;
	PetiteSuite ps;
	GrandeSuite gs;
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

void Player::afficheFigureToDo(std::vector<int> dice)
{
	for (int i = 0; i < _figureToDo.size(); i++) {
		_figureToDo[i].setDice(dice);
		std::cout << i << " : " << _figureToDo[i].getName() << "  score possible : "<< _figureToDo[i].getScore()<< std::endl;
	}
}

void Player::affichePlayer()
{
	std::cout << "Joueur no " << _id << " : " << _name << ", score : "<< _score << std::endl;
}
