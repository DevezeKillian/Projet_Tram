#ifndef LECTUREFICHIER_H
#define LECTUREFICHIER_H

#include <fstream>
#include <vector>
#include "arret.h"
#include "tram.h"
#include "ListeChaine.h"
#include "listeChaineTram.h"

/**
	Author : Arthur BIALEK
	Version : 1.0
*/

class LectureFichier {
public:
	LectureFichier(std::string fichierALire);
	void chainageArret(vector<ListeChaine*> &tab);
	void chainageTram(vector<listeChaineTram*> &tab, int nbLignes);
private:
	std::string d_fichier;
};

#endif