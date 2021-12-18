//Nathan Hubert
//Valentin Lescorbie

#pragma once
#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

class Figure {//Classe Figure classe mere de toute les figuire possible du jeu
protected:
	std::string _name;
	std::vector<int> _result_lancer;
	int _score;
	// Trois attributs : 
	// _name : le nom de la figure 
	// _result_lancer : tableau de int correspondant au tableau d'occurence des face de dés
	// _score : le score correspondant à la figure en relation avec le _result_lancer
public:

	Figure(std::string name); //contructeur de la Figure 
	virtual void calculScore(); //calcule le score de la figure, virtual car des figure n'ont pas le même calcul de score 
	virtual bool isFigure(); //regarde si le tabelau d'occurence (_result_lancer) correspond pour que la figure soit validé 
	int getScore(); //renvoie le _score 
	std::string getName();//renvoie le nom de la figure
	void setDice(std::vector<int> dices); //rentre les donné d'un lancer dans la figure

};

#endif // _FIGURE_H_


