#ifndef TRAM_H
#define TRAM_H
#include <windows.h>
#include <time.h>
#include "arret.h"
#include "ListeChaine.h"
#include <vector>

/**
	Author : Arthur BIALEK
	Version : 1.0
*/

class tram {
	friend class listeChaineTram;
public:
	//constructeurs
	tram();
	tram(float vitesse);
	tram(float vitesse, arret* arret);
	tram(const tram& tramACopier);

	//getter
	float vitesse()const;
	float vitesseInit() const;
	arret* getArret()const;
	float X();
	float Y();
	tram* suivant();
	bool getStop();
	int GetCpt();
	

	//setter
	void setVitesse(float vitesse);
	void setArret(arret* pointeurArret);
	void setX(float x);
	void setY(float y);
	void setSuivant(tram* suivant);
	void SetStop(const bool bl);
	void ReduceVit();
	void RetourVitInit();

	//methodes
	void defineEquation(arret* arretDepart, arret* arretArrive,const bool Operateur);
	bool ProcheQuai(arret* suivant);
	void IncrCpt();
	void RenitCpt();

	//test
	bool EstEnQuai();


private:
	float d_vitesseItnit;
	float d_vitesse;
	float d_X;
	float d_Y;
	arret* d_arret;
	tram* d_suivant;
	bool d_EstStop;
	int d_cptStop;
};

#endif