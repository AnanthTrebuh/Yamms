#include "Game.h"

Game::Game()
{
	_players = initPlayer();
	_lancer = Lancer();
}

std::vector<Player> Game::initPlayer()
{
	std::vector<Player> players;
	int nb_joueur;
	std::cout << "Veuillez saisir le nombre de joueur : " << std::endl;
	while (!(std::cin >> nb_joueur) || nb_joueur < 1) {
		std::cerr << "le nombre de joueur ne correspond pas recommencer s'il vous plait :" << std::endl;
		std::cin.clear(); // effacer les bits d'erreurs 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // supprimer la ligne erronée dans le buffer
	}
	for (int i = 0; i < nb_joueur; i++) {
		std::string name;
		std::cout << "Quel est le nom du joueur no " << i + 1 << "?" << std::endl;
		std::cin >> name; 
		Player p = Player(i + 1, name);
		players.push_back(p);
	}

	return players;
}

void Game::turnOfGame()
{	
	for (Player p : _players) {
		initDice();
		for (int i = 0; i < 3; i++) {
			std::cout << "Lancer No : " << i + 1 << std::endl;
			_lancer.jet();
			_lancer.affiche();
			std::cout << "Quel Des voulez vous gardez ?(0 pour passez)" << std::endl;
			int num_des;
			do {
				while (!(std::cin >> num_des) || num_des < 0 || num_des > 5) {
					std::cerr << "ce des n'existe pas, recommencez :" << std::endl;
					std::cin.clear(); // effacer les bits d'erreurs 
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // supprimer la ligne erronée dans le buffer
				}
				if (num_des != 0) {
					//_lancer.getDice()[num_des - 1].setKeep(true);
				}
			} while (num_des != 0);
		}
	}
}

std::vector<Player> Game::getPlayer()
{
	return _players;
}

void Game::affichePlayerGame()
{
	for (Player p : _players) {
		p.affichePlayer();
	}
}

void Game::initDice()
{
	for (Des d : _lancer.getDice()) {
		d.setKeep(false);
	}
}
