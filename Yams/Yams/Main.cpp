//Nathan Hubert
//Valentin Lescorbie

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

#include <chrono>
#include <thread>
#include "Game.h"
#include "Test.h"


int main() {
	
	srand(time(NULL));

	Test();

	Game g = Game();
	g.letsPlay();
}