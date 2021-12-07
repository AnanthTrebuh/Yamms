//Nathan Hubert
//Valentin Lescorbie

#pragma once
#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

class Figure {
protected:
	std::string _name;
	std::vector<int> _result_lancer;
	int _score;

public:

	Figure(const std::vector<int> result_lancer, std::string name);
	virtual int calculScore() = 0;
	virtual bool isFigure();
	int getScore();

};

#endif // _FIGURE_H_

