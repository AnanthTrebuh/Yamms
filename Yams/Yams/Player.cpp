//Valentin Lescorbie
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
#include <cstdio>

Player::Player()//constructeur par défault
{
	_id = 0;
	_name = "None";
	_score = 0;
	_figures = std::vector<Figure*>();
	_figureToDo = std::vector<Figure*>();
	addFigureTodo();	
}

Player::Player(int id, std::string name): _id(id), _name(name) //constructeur avec les paramètre d'identifiant et le nom du joueur
{
	_score = 0;
	_figures = std::vector<Figure*>();
	_figureToDo = std::vector<Figure*>();
	addFigureTodo();
}

Player::Player(const Player& p)//constructeur par copie 
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

Player& Player::operator=(Player& p)//redéfinition de l'opérateur égale
{
	Player pl = Player(p);
	return pl;
}

Player::~Player()//destructeur du Player
{

}

void Player::calculScore()//calcule le score du joueur, regarde le score de chaque Figure et l'ajoute au score, 
//si la figure viens de la partieSupérieur on l'ajoute à une autre variable pour vérifié si le score arrive ou dépasse 63 pour offrir une prime au Score
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
}

void Player::addFigure(int i, std::vector<int> dices)// ajoute une figure se trouvant dans le tableau des figure a faire vers le tableau des figure faite
//en lui ajoutant son tabelau d'occurence
//et en supprimant la figure ç faire du tableau de figure à faire
{
	_figureToDo[i]->setDice(dices);
	_figures.push_back(_figureToDo[i]);
	_figureToDo.erase(_figureToDo.begin() + i);
}

int Player::getScore()//renvoie le score du joueur
{
	return _score;
}

void Player::addFigureTodo()// initialise le tableau de figure à faire 
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

std::vector<Figure*> Player::getFigureTodo() //renvoie le tableau de figure à faire
{
	return _figureToDo;
}

std::string Player::getName()//renvoie le nom du joueur
{
	return _name;
}

void Player::afficheFigureToDo(std::vector<int> dice)//affiche les figure à faire en indiquant aussi le nombre de point qui peuvent être fait avec le lancer actuel
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

void Player::affichePlayer()//affiche les information sur le joueur
{
	std::cout << "Joueur no " << _id << " : " << _name << ", score : "<< _score << std::endl;
}
