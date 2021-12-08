#pragma once
class Dice
{
private :
	int _id;
	int _valeur;
	bool _keep = false;
public :
	Dice();
	Dice(int id);
	Dice(const Dice& d);
	Dice& operator=(Dice& d);
	~Dice();
	int jet();
	int getId();
	int getValeur();
	bool isKeep();
	void setKeep(bool keep);
	void affiche();
	void affiche1();
	void affiche2();
	void affiche3();
	void affiche4();
	void affiche5();
	void affiche6();
};

