//Valentin Lescorbie
//Nathan Hubert
#include "GrandeSuite.h"
#include <algorithm>
#include <vector>

GrandeSuite::GrandeSuite(std::vector<int> lancer) : Figure(lancer, "GrandeSuite")
{
	_score = calculScore();
}

int GrandeSuite::calculScore()
{
	int res = 0;
	if (isFigure()) {
		res = 40;
	}
	return res;
}

bool GrandeSuite::isFigure() {
	std::sort(_result_lancer.begin(), _result_lancer.end());
	int cpt = 1;
	int elemPrec = _result_lancer[0];
	
	for (unsigned int i = 1; i < _result_lancer.size(); i++) {
		if (_result_lancer[i] == elemPrec + 1) {
			elemPrec++;
			cpt++;
		}
	}
	return (cpt == 5);
}


//SEMBLE ETRE CODE POUR LA PETITE SUITE 
//bool GrandeSuite::isFigure()
//{
//	int taille = 0;
//	bool b = true;
//	int it = 0;
//
//	//Boucle pour tester a partir de chaque resultat il y a une suite
//	for (int i = 0; i < 5 && taille < 4; i++)
//	{
//		taille = 1;
//		it = i;
//		//tant qu'il y a une suite et qu'elle est inferieure a '
//		while (b && taille < 4)
//		{
//			b = false;
//			//Recherche d'une suite
//			for (int j = 0; j < 5 && !b; j++)
//			{
//				std::cout << "i = " << i << "\n";
//
//				if (_result_lancer[it] + 1 == _result_lancer[j]) {
//					it = j;
//					taille++;
//					b = true;
//					std::cout << "Taille = " << taille << "\n";
//				}
//			}
//			std::cout<<" b = " << b << "\n";
//		}
//	}
//	return (taille >= 4);
//}