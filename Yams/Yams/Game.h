#pragma once
#include "Player.h"
#include "Lancer.h"

class Game {
	std::vector<Player> _players;
	Lancer _lancer;
	//une game à un tableau de joueur _players
	//et un lancer 
public :
	Game();
	std::vector<Player> initPlayer();
	void turnOfGame(); 
	std::vector<Player> getPlayer();
	void affichePlayerGame();
	void initDice();
	void onePLayerTurn();
	void chooseFigure(Player& p);
	void calculeScore();
	void letsPlay();
	void theWinnerIs();
};