#ifndef LISTE_CHAINE_H_INCLUDED
#define LISTE_CHAINE_H_INCLUDED

#include <iostream>
#include <cassert>
#include "arret.h"

class ListeChaine
{
	friend std::ostream& operator<<(std::ostream& os, const ListeChaine& l);
	friend class arret;
public:
	ListeChaine();
	void Chainage(arret* nArret);
	void dedoublement();
	void Lire();
	int LongueurListe();
	void Supprimer(std::string nom);
	arret* RenvoieTete();
	arret* RenvoieQueue();
	//arret RevoieArret(const std::string Nom);
	arret* operator[](int i);
	void afficher(std::ostream& flux, const ListeChaine& lc) const;
private:
	arret* Debut;
	arret* Fin;
};

std::ostream& operator<<(std::ostream& os, const ListeChaine& l);

#endif // LISTE_CHAINE_H_INCLUDED
