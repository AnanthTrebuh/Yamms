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
	std::vector<Figure*> _figures;
	std::vector<Figure*> _figureToDo;
	//un joueur à 5 attribut
	//un identifiant _id
	//un nom _name
	//un score _score
	//un tabelau de figure faite _figure
	//un tabelau de figure à faire _figureToDo
public :
	Player();
	Player(int id, std::string name);
	Player(const Player& p);
	Player& operator=(Player& p);
	~Player();
	void calculScore();
	void addFigure(int i, std::vector<int> dices);
	int getScore();
	void addFigureTodo();
	std::vector<Figure*> getFigureTodo();
	std::string getName();
	void afficheFigureToDo(std::vector<int> dice);
	void affichePlayer();
};
#endif