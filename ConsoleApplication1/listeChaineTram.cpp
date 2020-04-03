#include "listeChaineTram.h"
/**
	Author : Hugo STAEDELIN
	Version : 1.0
*/

/**
	Constructeur par défaut de la liste chainée
*/
listeChaineTram::listeChaineTram() : d_tete{nullptr}
{
	d_tete = nullptr;
}

/**
	Destructeur de la liste chainée
*/
listeChaineTram::~listeChaineTram()
{
	while (d_tete != nullptr)
	{
		tram* aSupprimer = d_tete;
		d_tete = d_tete->d_suivant;
		delete aSupprimer;
	}
}

/**
	Ajout d'un chainon dans la liste (donc un tram)
*/
void listeChaineTram::ajout(tram* noTram)
{
	if (d_tete == nullptr)
	{
		d_tete = noTram;
		noTram->d_suivant = d_tete;
	}
	else
	{
		tram* nouvC = d_tete;
		while (nouvC->d_suivant != d_tete)
			nouvC = nouvC->d_suivant;

		nouvC->d_suivant = noTram;
		noTram->d_suivant = d_tete;
	}
}

tram* listeChaineTram::operator[](int i)
{
	tram* c = d_tete;
	int idx = 0;
	while (idx < i)
	{
		idx++;
		c = c->d_suivant;
	}
	return c;
}

ostream& operator<<(std::ostream& os, const listeChaineTram& lc)
{
	tram* tete = lc.d_tete;
	tram* c = lc.d_tete;
	do
	{
		os << "vitesse: " << c->vitesse() << std::endl << "arret: " << c->getArret() << std::endl;
		c = c->suivant();
	} while (c != tete);

	os << std::endl;
	return os;
}

tram* listeChaineTram::RenvoieTete()
{
	return d_tete;
}