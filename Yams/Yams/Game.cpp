#include "Game.h"

Game::Game()//constructeur 
{
	_players = initPlayer();
	_lancer = Lancer();
}

std::vector<Player> Game::initPlayer()//initialise les joueur en demandant combien de joueur et en les créant et les ajoutant au tableau de joueurs
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
 		Player p = Player((i + 1), name);
		players.push_back(p);
	}

	return players;
}

void Game::turnOfGame()//appel OnePlayerTurn pour chaque joueur 
{	
	for (int i = 0; i < _players.size(); i++)
	{
		initDice();
		std::cout << "Tour de : " << _players[i].getName() << std::endl;
		onePLayerTurn();//un tour de 3 lancer 
		std::cout << "Vous pouvez faire ces composition :" << std::endl;
		_players[i].afficheFigureToDo(_lancer.getTabOccur());
		chooseFigure(_players[i]);
	}
}

std::vector<Player> Game::getPlayer()//renvoie le tabelau de players
{
	return _players;
}

void Game::affichePlayerGame()//affiche les information de chaque joueur qui joue 
{
	for (Player p : _players) {
		p.affichePlayer();
	}
}

void Game::initDice()//initialise les des a _keep = false
{
	_lancer.resetDice();
}

void Game::onePLayerTurn()//un tours de jeu avec les trois lancé
{
	for (int i = 0; i < 3; i++) {
		std::cout << "Lancer No : " << i + 1 << std::endl;
		_lancer.jet();
		_lancer.affiche();
		if (i < 2) {
			std::cout << "\nQuel Des voulez vous gardez ?(0 pour passez)" << std::endl;
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
}

void Game::chooseFigure(Player& p)//permet de choisir la figure qu'on souhaite faire avec le lancer actuel
{
	int figure;
	std::cout << "Quel combinaison voulez vous faire avec vos des ?(entre le chiffre correspondant)" << std::endl;
	while (!(std::cin >> figure) && figure < 0 || figure > p.getFigureTodo().size()-1) {
		std::cerr << "Ce n'est pas une combinaison possible, recommencer" << std::endl;
		std::cin.clear(); // effacer les bits d'erreurs 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "Vous avez choisi : " << p.getFigureTodo().at(figure)->getName() << std::endl;
	
	p.addFigure(figure, _lancer.getTabOccur());
}

void Game::calculeScore() {//appel la focntion calculScore de chaque joueur 
	for (int i = 0; i < _players.size(); i++) {
		_players[i].calculScore();
	}
}

void Game::letsPlay()//correspond a une partie avec 13 tours pour chaque figure, le calcul du score et l'affichage du joueur avec le plus de points 
{
	const int nb_tours = 13;
	for (int i = 0; i < nb_tours; i++) {
		turnOfGame();
	}
	calculeScore();
	affichePlayerGame();
	theWinnerIs();
}

void Game::theWinnerIs()//cherche dans la liste des joueurs le joueurs avec le plus de points 
{
	int idWin = 0; 
	int score = 0;
	for (int i = 0; i < _players.size(); i++) {
		if (_players[i].getScore() > score) {
			idWin = i; 
		}
	}
	std::cout << "the winner is : " << std::endl;
	_players[idWin].affichePlayer();
}
