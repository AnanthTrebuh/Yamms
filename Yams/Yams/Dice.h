#pragma once
class Dice
{
private :
	int _id;
	int _valeur;
	bool _keep = false;
	//un des à 3 attribut
	//un identifiant _id
	//une valeur _valeur
	//un bool qui dit si ont garde le des ou non dans le lancer _keep
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

};

