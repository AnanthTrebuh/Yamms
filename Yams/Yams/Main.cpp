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


int main() {
	srand(time(NULL));

	/*Game g = Game();
	g.affichePlayerGame();
	g.turnOfGame();
	g.turnOfGame();*/






	std::cout << " _____" << std::endl;
	std::cout << "|*   *|" << std::endl;
	std::cout << "|  *  |" << std::endl;
	std::cout << "|*___*|" << std::endl;

	std::vector<int> resultLancerBon = { 0,0,0,0,5 };
	const int x = 5;
	Yahtzee c(resultLancerBon);
	std::cout << "yahtzee lancer Bon : " << c.getScore() << std::endl;
	std::vector<int> resultLancerBad = { 0,0,0,0,4 };
	Yahtzee c1(resultLancerBad);
	std::cout << "yahtzee lancer Mauvais : " << c1.getScore() << std::endl;


	std::vector<int> resultLancerBon2 = { 0,0,0,0,5 };
	Chance c2(resultLancerBon2);
	std::cout << "Chance toujours bon : " << c2.getScore() << std::endl;


	std::vector<int> resultLancerBon3 = { 4,0,0,0,0 };
	Carre c3(resultLancerBon3);
	std::cout << "Carre lancer Bon : " << c3.getScore() << std::endl;
	std::vector<int> resultLancerBad3 = { 0,0,0,0,3 };
	Carre c3Bad(resultLancerBad3);
	std::cout << "Carre lancer Mauvais : " << c3Bad.getScore() << std::endl;

	std::vector<int> resultLancerBon4 = { 3,2,0,0,0 };
	Full c4(resultLancerBon4);
	std::cout << "Full lancer Bon : " << c4.getScore() << std::endl;
	std::vector<int> resultLancerBad4= { 1,2,2,0,0 };
	Full c4Bad(resultLancerBad4);
	std::cout << "Full lancer mauvais: " << c4Bad.getScore() << std::endl;

	std::vector<int> resultLancerBon5 = { 0,0,3,0,0 };
	Brelan c5(resultLancerBon5);
	std::cout << "Brelan lancer bon : " << c5.getScore() << std::endl;
	std::vector<int> resultLancerBad5 = { 0,0,1,1,1 };
	Brelan c5Bad(resultLancerBad5);
	std::cout << "Brelan lancer mauvais : " << c5Bad.getScore() << std::endl;
	
	std::vector<int> resultLancerBon6 = { 1,1,1,1,1 };
	GrandeSuite c6(resultLancerBon6);
	std::cout << "GrandeSuite lancer Bon : " << c6.getScore() << std::endl;
	std::vector<int> resultLancerBad6 = { 0,0,0,0,5 };
	GrandeSuite c6Bad(resultLancerBad6);
	std::cout << "GrandeSuite lancer mauvais : " << c6Bad.getScore() << std::endl;
	
	std::vector<int> resultLancerBon7 = { 0,1,1,1,1 };
	PetiteSuite c7(resultLancerBon7);
	std::cout << "Petite suite lancer bon : " << c7.getScore() << std::endl;
	std::vector<int> resultLancerBad7 = { 0,0,0,0,5 };
	PetiteSuite c7Bad(resultLancerBad7);
	std::cout << "petite suite lancer mauvais : " << c7Bad.getScore() << std::endl;
	std::vector<int> resLancer = { 0,0,0,0,5 };
	std::sort(resLancer.begin(), resLancer.end());
	for (int des : resLancer) {
		std::cout << des << ", ";
	}

	std::vector<int> resultLancerpartSup1 = { 2,0,0,0,0 };
	std::vector<int> resultLancerpartSup2 = { 0,3,0,0,2 };
	std::vector<int> resultLancerpartSup3 = { 0,0,0,0,5 };
	std::vector<int> resultLancerpartSup4 = { 0,0,0,0,5 };
	std::vector<int> resultLancerpartSup5 = { 0,0,0,0,5 };
	std::vector<int> resultLancerpartSup6 = { 0,0,0,0,5 };
	std::vector<int> resultLancerpartSup7 = { 0,0,0,0,5 };
	std::vector<int> resultLancerpartSup8 = { 0,0,0,0,5 };

	PartieSuperieure<1> ps1(resultLancerpartSup1);
	PartieSuperieure<2> ps2(resultLancerpartSup2);
	PartieSuperieure<5> ps3(resultLancerpartSup3);
	PartieSuperieure<4> ps4(resultLancerpartSup4);
	PartieSuperieure<3> ps5(resultLancerpartSup5);
	PartieSuperieure<6> ps6(resultLancerpartSup6);
	PartieSuperieure<2> ps7(resultLancerpartSup7);
	PartieSuperieure<1> ps8(resultLancerpartSup8);

	std::cout << "\n\nPartie sup avec plusieur possibilité" << std::endl;
	std::cout << "attendu : 5 resultat : " << ps1.getScore() << std::endl;
	std::cout << "attendu : 4 resultat : " << ps2.getScore() << std::endl;
	std::cout << "attendu : 0 resultat : " << ps3.getScore() << std::endl;
	std::cout << "attendu : 0 resultat : " << ps4.getScore() << std::endl;
	std::cout << "attendu : 3 resultat : " << ps5.getScore() << std::endl;
	std::cout << "attendu : 30 resultat : " << ps6.getScore() << std::endl;
	std::cout << "attendu : 2 resultat : " << ps7.getScore() << std::endl;
	std::cout << "attendu : 1 resultat : " << ps8.getScore() << std::endl;

	/*std::cout << "\n\nTest de la classe player\n";
	
	Player p = Player(1, "Jean");
	p.addFigure(c);
	p.addFigure(c2);
	p.addFigure(c3);
	p.addFigure(c4);
	p.addFigure(c5);
	p.addFigure(c6);
	p.addFigure(c7);
	p.addFigure(ps1);
	p.addFigure(ps2);
	p.addFigure(ps3);
	p.addFigure(ps4);
	p.addFigure(ps5);
	p.addFigure(ps6);
	std::cout << "Ajout de toutes les figures valide a un joueur, ";
	std::cout << p.getName() << " : " << p.getScore() << " attendu 249\n";


	Player p2 = Player(2, "Paul");
	
	p2.addFigure(c1);
	p2.addFigure(c3Bad);
	p2.addFigure(c4Bad);
	p2.addFigure(c5Bad);
	p2.addFigure(c6Bad);
	p2.addFigure(c7Bad);
	std::cout << "Ajout de toutes les figures invalide a un joueur, ";
	std::cout << p2.getName() << " : " << p2.getScore() << " attendu 0\n";*/

	/*std::cout << "\n\nTest de la classe Des\n";
	Des d = Des(1);
	for (int i = 0; i < 10; i++)
	{
		d.jet();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

		std::cout << "nouvelle valeur du de : " << d.getValeur() << "\n";
		d.affiche();
	}*/

	/*std::cout << "test Classe Lancer ..." << std::endl;
	Lancer l = Lancer();
	l.jet();
	for (Des d : l.getDice()) {
		std::cout << d.getId() <<  " : " << d.getValeur() << std::endl;
	}
	l.getDice()[1].setKeep(true);
	l.affiche();*/
}