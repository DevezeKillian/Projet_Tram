#include <iostream>
#include "LectureFichier.h"
#include <vector>
#include <string>


/**
	Author : Arthur BIALEK
	Version : 1.0
*/

//Constructeurs
LectureFichier::LectureFichier(std::string fichierALire): d_fichier{ fichierALire }
{
}

//Methodes
void LectureFichier::chainageArret(vector<ListeChaine*>& tab)
{
	int lignes, arrets, X, Y;
	std::string p, nom;

	ifstream LectureArrets(d_fichier);

	LectureArrets >> p >> lignes;
	for (int i = 0; i < lignes; ++i)
	{
		ListeChaine* liste;
		liste = new ListeChaine();
		LectureArrets >> p >> arrets;
		for (int j = 0; j < arrets; ++j)
		{
			LectureArrets >> p >> nom >> p >> X >> p >> Y;
			liste->Chainage(new arret(nom, X, Y));
		}
		if (arrets > 2)
		{
			liste->dedoublement();
		}
		tab.push_back(liste);
	}
}

void LectureFichier::chainageTram(vector<listeChaineTram*>& tab, int nbLigne)
{
	int trams, vitesse;
	std::string p, numero;

	ifstream LectureTrams(d_fichier);

	for (int i = 0; i < nbLigne; ++i)
	{
		listeChaineTram* liste;
		liste = new listeChaineTram();
		LectureTrams >> p >> trams;
		for (int j = 0; j < trams; ++j)
		{
			LectureTrams >> p >> numero;
			LectureTrams >> p >> vitesse;
			liste->ajout(new tram(vitesse));
		}
		tab.push_back(liste);
	}
}