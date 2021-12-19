//Nathan Hubert
//Valentin Lescorbie

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

#include <chrono>
#include <thread>
#include "Carre.h"
#include "Chance.h"
#include "Full.h"
#include "Yahtzee.h"
#include "GrandeSuite.h"
#include "PetiteSuite.h"
#include "Brelan.h"
#include "PartieSuperieure.h"
#include "Player.h"
#include "Dice.h"
#include "Lancer.h"
#include "Game.h"
#include "Test.h"


int main() {
	
	srand(time(NULL));

	Test();

	Game g = Game();
	/*g.affichePlayerGame();
	g.turnOfGame();
	g.turnOfGame();*/

	g.letsPlay();
}