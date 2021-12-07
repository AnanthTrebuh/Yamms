//Nathan Hubert
//Valentin Lescorbie

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

#include "Carre.h"
#include "Chance.h"
#include "Full.h"
#include "Yahtzee.h"
#include "GrandeSuite.h"
#include "PetiteSuite.h"
#include "Brelan.h"
#include "PartieSuperieure.h"
#include "Player.h"

int main() {
	std::cout << "______" << std::endl;
	std::cout << "|*   *|" << std::endl;
	std::cout << "|  *  |" << std::endl;
	std::cout << "|*___*|" << std::endl;

	std::vector<int> resultLancerBon = { 5,5,5,5,5 };
	const int x = 5;
	Yahtzee<x> c(resultLancerBon);
	std::cout << "yahtzee lancer Bon : " << c.getScore() << std::endl;
	std::vector<int> resultLancerBad = { 5,5,5,6,5 };
	Yahtzee<5> c1(resultLancerBad);
	std::cout << "yahtzee lancer Mauvais : " << c1.getScore() << std::endl;


	std::vector<int> resultLancerBon2 = { 5,5,1,3,6 };
	Chance c2(resultLancerBon2);
	std::cout << "Chance toujours bon : " << c2.getScore() << std::endl;


	std::vector<int> resultLancerBon3 = { 5,5,5,5,4 };
	Carre<5> c3(resultLancerBon3);
	std::cout << "Carre lancer Bon : " << c3.getScore() << std::endl;
	std::vector<int> resultLancerBad3 = { 5,5,5,3,4 };
	Carre<5> c3Bad(resultLancerBad3);
	std::cout << "Carre lancer Mauvais : " << c3Bad.getScore() << std::endl;

	std::vector<int> resultLancerBon4 = { 5,5,5,1,1 };
	Full<5, 1> c4(resultLancerBon4);
	std::cout << "Full lancer Bon : " << c4.getScore() << std::endl;
	std::vector<int> resultLancerBad4= { 5,5,5,5,5 };
	Full<5, 4> c4Bad(resultLancerBad4);
	std::cout << "Full lancer mauvais: " << c4Bad.getScore() << std::endl;

	std::vector<int> resultLancerBon5 = { 5,5,2,1,5 };
	Brelan<5> c5(resultLancerBon5);
	std::cout << "Brelan lancer bon : " << c5.getScore() << std::endl;
	std::vector<int> resultLancerBad5 = { 5,5,1,2,3 };
	Brelan<5> c5Bad(resultLancerBad5);
	std::cout << "Brelan lancer mauvais : " << c5Bad.getScore() << std::endl;
	
	std::vector<int> resultLancerBon6 = { 2,1,3,4,5 };
	GrandeSuite c6(resultLancerBon6);
	std::cout << "GrandeSuite lancer Bon : " << c6.getScore() << std::endl;
	std::vector<int> resultLancerBad6 = { 1,2,5,4,5 };
	GrandeSuite c6Bad(resultLancerBad6);
	std::cout << "GrandeSuite lancer mauvais : " << c6Bad.getScore() << std::endl;
	
	std::vector<int> resultLancerBon7 = { 1,1,3,2,4 };
	PetiteSuite c7(resultLancerBon7);
	std::cout << "Petite suite lancer bon : " << c7.getScore() << std::endl;
	std::vector<int> resultLancerBad7 = { 5,5,5,5,5 };
	PetiteSuite c7Bad(resultLancerBad7);
	std::cout << "petite suite lancer mauvais : " << c7Bad.getScore() << std::endl;
	std::vector<int> resLancer = { 1,5,8,4,8 };
	std::sort(resLancer.begin(), resLancer.end());
	for (int des : resLancer) {
		std::cout << des << ", ";
	}

	std::vector<int> resultLancerpartSup1 = { 1,1,1,1,1 };
	std::vector<int> resultLancerpartSup2 = { 2,2,3,4,5 };
	std::vector<int> resultLancerpartSup3 = { 2,1,6,4,6 };
	std::vector<int> resultLancerpartSup4 = { 2,1,3,5,5 };
	std::vector<int> resultLancerpartSup5 = { 2,1,3,4,5 };
	std::vector<int> resultLancerpartSup6 = { 6,6,6,6,6 };
	std::vector<int> resultLancerpartSup7 = { 2,1,3,4,5 };
	std::vector<int> resultLancerpartSup8 = { 2,1,3,4,5 };

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

	std::cout << "\n\nTest de la classe player\n";
	
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
	std::cout << p2.getName() << " : " << p2.getScore() << " attendu 0\n";


}