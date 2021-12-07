#include "Player.h"

Player::Player()
{
	_id = 0;
	_name = "None";
	_score = 0;
	_figures = std::vector<Figure>();
	_figureToDo = std::vector<std::string>();

}

Player::Player(int id, std::string name): _id(id), _name(name)
{
	_score = 0;
	_figures = std::vector<Figure>();
	_figureToDo = std::vector<std::string>();
}

Player::Player(const Player& p)
{
	_id = p._id;
	_name = p._name;
	_score = p._score;
	_figures = p._figures;
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

void Player::addFigure(Figure& fig)
{
	for (int i = 0; i < _figureToDo.size(); i++)
	{
		if (fig.getName() == _figureToDo.at(i)) {
			_figures.push_back(fig);
			_figureToDo.erase(_figureToDo.begin() + i);
		}
	}
}
