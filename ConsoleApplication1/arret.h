#ifndef ARRET_H
#define ARRET_H

#include <string>

/**
	Author : Arthur BIALEK
	Version : 1.0
*/
using namespace std;

class arret {
	friend class ListeChaine;
public:
	//Constructeurs
	arret();
	arret(string nom);
	arret(string nom, int X, int Y);

	//Getters
	string nom() const;
	float X();
	float Y();
	arret* GetSuiv();

	//Setters
	void setNom(string nom);
	void setX(int X);
	void setY(int Y);
	void setSuiv(arret* a);

private:
	string d_nom;
	int d_X, d_Y;
	arret* d_suivant, * d_precedent;
};

#endif
