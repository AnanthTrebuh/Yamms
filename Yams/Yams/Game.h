#pragma once
#include "Player.h"
#include "Lancer.h"

class Game {
	std::vector<Player> _players;
	Lancer _lancer;
public :
	Game();
	std::vector<Player> initPlayer();
	void turnOfGame(); 
	std::vector<Player> getPlayer();
	void affichePlayerGame();
	void initDice();
	std::vector<int> getValueDice();
	void onePLayerTurn();
	void chooseFigure(Player& p);
	std::vector<int> makeDiceTab();
};