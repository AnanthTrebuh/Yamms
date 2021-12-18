#include "Player.h"
#include "Carre.h"
#include "Chance.h"
#include "Full.h"
#include "Yahtzee.h"
#include "GrandeSuite.h"
#include "PetiteSuite.h"
#include "Brelan.h"
#include "PartieSuperieure.h"
#include <string>

Player::Player()
{
	_id = 0;
	_name = "None";
	_score = 0;
	_figures = std::vector<Figure*>();
	_figureToDo = std::vector<Figure*>();
	addFigureTodo();	
}

Player::Player(int id, std::string name): _id(id), _name(name)
{
	_score = 0;
	_figures = std::vector<Figure*>();
	_figureToDo = std::vector<Figure*>();
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
	int psScore = 0;
	for (int i = 0; i < _figures.size(); i++)
	{
		if (_figures.at(i)->getName().find("PartieSuperieur") != std::string::npos) {
			psScore += _figures.at(i)->getScore();
		}
		scr += _figures.at(i)->getScore();
		if (psScore >= 63) {
			scr += 35;
		}
	}
	_score = scr;
	return scr;
}

void Player::addFigure(int i, std::vector<int> dices)
{
	_figureToDo[i]->setDice(dices);
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
	PartieSuperieure<1>* p1 = new PartieSuperieure<1>();
	PartieSuperieure<2>* p2 = new PartieSuperieure<2>();
	PartieSuperieure<3>* p3 = new PartieSuperieure<3>();
	PartieSuperieure<4>* p4 = new PartieSuperieure<4>();
	PartieSuperieure<5>* p5 = new PartieSuperieure<5>();
	PartieSuperieure<6>* p6 = new PartieSuperieure<6>();
	Chance* c = new Chance();
	Brelan* b = new Brelan();
	Yahtzee* y = new Yahtzee();
	Carre* carre = new Carre();
	Full* f = new Full();
	PetiteSuite* ps = new PetiteSuite();
	GrandeSuite* gs = new GrandeSuite();
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

std::vector<Figure*> Player::getFigureTodo()
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
		if (_figureToDo.at(i) == nullptr) {
			std::cout << "figure nulle \n";
		}
		else {
			_figureToDo[i]->setDice(dice);
			std::cout << i << " : " << _figureToDo[i]->getName() << "  score possible : " << _figureToDo[i]->getScore() << std::endl;
		}
		
	}
}

void Player::affichePlayer()
{
	std::cout << "Joueur no " << _id << " : " << _name << ", score : "<< _score << std::endl;
}
