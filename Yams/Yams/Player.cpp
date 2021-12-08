#include "Player.h"

Player::Player()
{
	_id = 0;
	_name = "None";
	_score = 0;
	_figures = std::vector<Figure>();
	_figureToDo = std::vector<std::string>();
	_figureToDo.push_back("Chance");
	_figureToDo.push_back("Brelan");
	_figureToDo.push_back("Yahtzee");
	_figureToDo.push_back("Carre");
	_figureToDo.push_back("Full");
	_figureToDo.push_back("PetiteSuite");
	_figureToDo.push_back("GrandeSuite");
	_figureToDo.push_back("PartieSuperieur1");
	_figureToDo.push_back("PartieSuperieur2");
	_figureToDo.push_back("PartieSuperieur3");
	_figureToDo.push_back("PartieSuperieur4");
	_figureToDo.push_back("PartieSuperieur5");
	_figureToDo.push_back("PartieSuperieur6");


}

Player::Player(int id, std::string name): _id(id), _name(name)
{
	_score = 0;
	_figures = std::vector<Figure>();
	_figureToDo = std::vector<std::string>();
	_figureToDo.push_back("Chance");
	_figureToDo.push_back("Brelan");
	_figureToDo.push_back("Yahtzee");
	_figureToDo.push_back("Carre");
	_figureToDo.push_back("Full");
	_figureToDo.push_back("PetiteSuite");
	_figureToDo.push_back("GrandeSuite");
	_figureToDo.push_back("PartieSuperieur1");
	_figureToDo.push_back("PartieSuperieur2");
	_figureToDo.push_back("PartieSuperieur3");
	_figureToDo.push_back("PartieSuperieur4");
	_figureToDo.push_back("PartieSuperieur5");
	_figureToDo.push_back("PartieSuperieur6");

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

void Player::addFigure(Figure& fig)
{
	for (int i = 0; i < _figureToDo.size(); i++)
	{
		if (fig.getName() == _figureToDo.at(i)) {
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

std::string Player::getName()
{
	return _name;
}

void Player::affichePlayer()
{
	std::cout << "Joueur no " << _id << " : " << _name << std::endl;
}
