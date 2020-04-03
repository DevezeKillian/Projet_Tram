#include "ListeChaine.h"
#include "arret.h"
#include <iostream>
#include <vector>
/**
	Author : Killian Deveze
*/

//Constructeur par defaut de la la classe ListeChaine
ListeChaine::ListeChaine() : Debut{ nullptr }, Fin{ nullptr }
{
}

/**
	but : methode pour ajouter un nouvel élements dans la chaine (la ligne de tram) de type Arret.
		  la fonction test si un élements est déjà présent ou non
	Entrées : un élement du type de la classe Arret
*/
void ListeChaine::Chainage(arret* nArret)
{
	if (Debut == nullptr && Fin == nullptr)
	{
		Debut = nArret;
		Fin = nArret;
		return;
	}
	else
		if (Debut == Fin)
		{
			Debut->d_suivant = nArret;
			Fin = nArret;
			nArret->d_suivant = Debut;
		}
		else
		{
			nArret->d_suivant = Debut;
			Fin->d_suivant = nArret;
			Fin = nArret;
		}
}
/**
	but : la fonction renvoie la taille , le nombre d'élements présent dans la liste
*/
int ListeChaine::LongueurListe()
{
	int cpt = 0;
	arret* tmp = Debut;
	if (tmp == nullptr)
		return 0;
	do
	{
		++cpt;
		tmp = tmp->d_suivant;
	} while (tmp != Debut);

	return cpt;
}
/**
	But : Permet de rendre la liste circulaire en miroir , càd que la liste comporte deux fois les même chainons
	mais dans un ordre inverse
*/
void ListeChaine::dedoublement()
{
	int cpt = LongueurListe() - 2;
	int nb = 0;
	int i = 0;
	vector <arret> tmp(cpt);
	arret* c = Debut->d_suivant;
	//cout << "----------------------------------" << endl;
	do
	{
		tmp[i] = *c;
		c = c->d_suivant;
		//cout<<tmp[i].d_nom<<endl;
		++nb;
		++i;
	} while (c->d_suivant != Debut);

	for (int i = nb - 1; i >= 0; --i)
	{
		arret* nc = new arret(tmp[i].d_nom, tmp[i].d_X, tmp[i].d_Y);
		//cout << nc->d_nom<<endl;
		Fin->d_suivant = nc;
		Fin = Fin->d_suivant;
		
	}

	Fin->d_suivant = Debut;
}

/**
	But : permet de lire les élements de la liste
*/
void ListeChaine::Lire()
{
	arret* tmp = Debut;

	for (int i = 0; i <= LongueurListe() - 1; ++i)
	{
		//cout<<Debut->d_nom;
		cout << tmp->d_nom << endl;
		tmp = tmp->d_suivant;
	}
}

arret* ListeChaine::RenvoieTete()
{
	return Debut;
}

arret* ListeChaine::RenvoieQueue()
{
	return Fin;
}
/*
arret ListeChaine::RevoieArret(const std::string Nom)
{
	return arret();
}
*/

ostream& operator<<(std::ostream& os, const ListeChaine& lc)
{
	lc.afficher(os, lc);
	return os;
}

void ListeChaine::Supprimer(std::string valeur)
{
	arret* precC = nullptr, * c = Debut;

	// Cas de la liste vide
	if (Debut == nullptr)
		return;

	// Cas de la suppression de la tete
	if (valeur == Debut->d_nom)
	{
		Debut = c->d_suivant;
		delete c;
		return;
	}

	// Cas de la suppression au milieu de la liste
	// On cherche d'abord le chainon
	while (c != Debut && c->d_nom != valeur)
	{
		precC = c;
		c = c->d_suivant;
	}

	// On le supprime ensuite
	if (c != Debut && c->d_nom == valeur)
	{
		precC->d_suivant = c->d_suivant;
		delete c;
	}
}

arret* ListeChaine::operator[](int i)
{
	arret* c = Debut;
	int idx = 0;
	while (idx < i)
	{
		idx++;
		c = c->d_suivant;
	}
	return c;
}


void ListeChaine::afficher(std::ostream& flux, const ListeChaine& lc) const
{
	arret* tete = lc.Debut;
	arret* c = lc.Debut;
	do
	{
		flux << c->nom() << std::endl;
		c = c->d_suivant;
	} while (c != tete);

	flux << std::endl;
}