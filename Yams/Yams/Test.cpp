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

Test::Test()
{
	figureTest();
	playerTest();
	diceTest();
	lancerTest();
}

void Test::figureTest()
{
	std::cout << "\t _____" << std::endl;
	std::cout << "\t|     |" << std::endl;
	std::cout << "\t|  *  |" << std::endl;
	std::cout << "\t|_____|" << std::endl;
	std::cout << "\nTESTS DE LA PARTIE INFERIEURE\n\n";
	Yahtzee c;
	c.setDice({ 0,5,0,0,0,0 });
	std::cout << "yahtzee lancer Bon : " << c.getScore() << std::endl;
	Yahtzee c1;
	c1.setDice({ 1,2,3,0,0,0 });
	std::cout << "yahtzee lancer Mauvais : " << c1.getScore() << std::endl;


	Chance c2;
	c2.setDice({ 5,0,0,0,0,0 });
	std::cout << "Chance toujours bon : " << c2.getScore() << std::endl;


	std::vector<int> dice = { 4,0,0,0,0,0 };
	std::vector<int> dice2 = { 3,0,3,0,0,0 };


	Carre c3;
	c3.setDice(dice);
	std::cout << "Carre lancer Bon : " << c3.getScore() << std::endl;
	Carre c3Bad;
	c3Bad.setDice(dice2);
	std::cout << "Carre lancer Mauvais : " << c3Bad.getScore() << std::endl;

	Full c4;
	c4.setDice({ 3,2,0,0,0,0 });
	std::cout << "Full lancer Bon : " << c4.getScore() << std::endl;
	Full c4Bad;
	c4Bad.setDice({ 3,1,1,0,0,0 });
	std::cout << "Full lancer mauvais: " << c4Bad.getScore() << std::endl;

	Brelan c5;
	c5.setDice({ 3,0,1,1,0,0 });
	std::cout << "Brelan lancer bon : " << c5.getScore() << std::endl;
	Brelan c5Bad;
	c5Bad.setDice({ 2,1,1,1,0,0 });
	std::cout << "Brelan lancer mauvais : " << c5Bad.getScore() << std::endl;


	GrandeSuite c6;
	c6.setDice({ 1,1,1,1,1,0 });
	std::cout << "GrandeSuite lancer Bon : " << c6.getScore() << std::endl;
	GrandeSuite c6Bad;
	c6Bad.setDice({ 1,1,1,0,0,0 });
	std::cout << "GrandeSuite lancer mauvais : " << c6Bad.getScore() << std::endl;


	PetiteSuite c7;
	c7.setDice({ 0,1,1,1,1,1 });
	std::cout << "Petite suite lancer bon : " << c7.getScore() << std::endl;
	PetiteSuite c7Bad;
	c7Bad.setDice({ 1,1,1,0,1,1 });

	std::cout << "petite suite lancer mauvais : " << c7Bad.getScore() << std::endl;


	std::cout << "\n\t _____" << std::endl;
	std::cout << "\t|    *|" << std::endl;
	std::cout << "\t|     |" << std::endl;
	std::cout << "\t|*____|" << std::endl;
	std::cout << "\nTESTS DE LA PARTIE SUPERIEURE\n\n";

	std::vector<int> resultLancerpartSup1 = { 2,0,0,0,0,0 };
	std::vector<int> resultLancerpartSup2 = { 0,3,0,0,2,0 };
	std::vector<int> resultLancerpartSup3 = { 0,0,0,0,5,0 };
	std::vector<int> resultLancerpartSup4 = { 0,0,0,0,5,0 };
	std::vector<int> resultLancerpartSup5 = { 0,0,0,0,5,0 };
	std::vector<int> resultLancerpartSup6 = { 0,0,0,0,5,0 };
	std::vector<int> resultLancerpartSup7 = { 0,0,0,0,5,0 };
	std::vector<int> resultLancerpartSup8 = { 0,0,0,0,5,0 };

	PartieSuperieure<1> ps1;
	PartieSuperieure<2> ps2;
	PartieSuperieure<5> ps3;
	PartieSuperieure<4> ps4;
	PartieSuperieure<3> ps5;
	PartieSuperieure<2> ps7;
	PartieSuperieure<1> ps8;

	std::cout << "Partie sup avec plusieur possibilité" << std::endl;
	std::cout << "attendu : 5 resultat : " << ps1.getScore() << std::endl;
	std::cout << "attendu : 4 resultat : " << ps2.getScore() << std::endl;
	std::cout << "attendu : 0 resultat : " << ps3.getScore() << std::endl;
	std::cout << "attendu : 0 resultat : " << ps4.getScore() << std::endl;
	std::cout << "attendu : 3 resultat : " << ps5.getScore() << std::endl;
	std::cout << "attendu : 2 resultat : " << ps7.getScore() << std::endl;
	std::cout << "attendu : 1 resultat : " << ps8.getScore() << std::endl;
}

void Test::playerTest()
{
	std::cout << "\n\t _____" << std::endl;
	std::cout << "\t|    *|" << std::endl;
	std::cout << "\t|  *  |" << std::endl;
	std::cout << "\t|*____|" << std::endl;
	std::cout << "\nTESTS DE LA CLASSE PLAYER\n\n";

	/*Player p = Player(1, "Jean");
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
}

void Test::diceTest()
{
	std::cout << "\n\t _____" << std::endl;
	std::cout << "\t|*   *|" << std::endl;
	std::cout << "\t|     |" << std::endl;
	std::cout << "\t|*___*|" << std::endl;
	std::cout << "\n\nTEST DE LA CLASSE DICE\n";
	Dice d = Dice(1);
	for (int i = 0; i < 10; i++)
	{
		d.jet();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

		std::cout << "nouvelle valeur du de : " << d.getValeur() << "\n";
	}
}

void Test::lancerTest()
{
	std::cout << "\n\t _____" << std::endl;
	std::cout << "\t|*   *|" << std::endl;
	std::cout << "\t|  *  |" << std::endl;
	std::cout << "\t|*___*|" << std::endl;
	std::cout << "\n\nTEST DE LA CLASSE LANCER\n";
	Lancer l = Lancer();
	l.jet();
	for (Dice d : l.getDice()) {
		std::cout << d.getId() << " : " << d.getValeur() << std::endl;
	}
	l.getDice()[1].setKeep(true);
	l.affiche();
}
