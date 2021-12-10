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
		onePLayerTurn();//un tour de 3 lancer 
		std::cout << "Vous pouvez faire ces composition :" << std::endl;
		p.afficheFigureToDo();
		chooseFigure(p);
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
	_lancer.resetDice();
}

std::vector<int> Game::getValueDice()
{
	std::vector<int> dices; 
	for (Dice d : _lancer.getDice()) {
		dices.push_back(d.getValeur());
	}
	return dices;
}

void Game::onePLayerTurn()
{
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
				num_des--;
				_lancer.getDice()[num_des].setKeep(true);
				num_des++;
			}
		} while (num_des != 0);
	}
}

void Game::chooseFigure(Player p)
{
	bool is_find = false;
	int figure;
	while (!is_find) {
		std::cout << "Quel combinaison voulez vous faire avec vos des ?(entré le chiffre correspondand" << std::endl;
		while (!(std::cin >> figure) && figure < 0 || figure > p.getFigureTodo().size()-1) {
			std::cerr << "Ce n'est pas une combinaison possible, recommencer" << std::endl;
			std::cin.clear(); // effacer les bits d'erreurs 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "Vous avez choisi : " << p.getFigureTodo().at(figure).getName() << std::endl;
		std::cout << "Etes vous d'accord avec ce choix ? (o/n)" << std::endl;
		char rep;
		std::cin >> rep;
		if (rep == 'o' || rep == 'O') {
			is_find = true;
		}
	}
	p.addFigure(p.getFigureTodo().at(figure), _lancer.getTabOccur());
}
