#pragma once
#include <cstdlib>
#include <iostream>
#include "Figure.h"
#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player {
private :
	int _id; 
	std::string _name;
	unsigned int _score;
	std::vector<Figure> _figures;
	std::vector<std::string> _figureToDo;
public :
	Player();
	Player(int id, std::string name);
	Player(const Player& p);
	Player& operator=(Player& p);
	~Player();
	int calculScore();
	void addFigure(Figure& fig);
	int getScore();
	std::string getName();
};
#endif