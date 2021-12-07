#pragma once
class Des
{
private :
	int _id;
	int _valeur;
public :
	Des();
	Des(int id);
	Des(const Des& d);
	Des& operator=(Des& d);
	~Des();
	int jet();
	int getId();
	int getValeur();
	void affiche();
};

