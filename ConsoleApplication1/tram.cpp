#include <iostream>
#include <SFML/Graphics.hpp>
#include "tram.h"
#include "arret.h"
#include "Interface.h"
#include <math.h>

/**
	Author : Arthur BIALEK
	Version : 1.0
*/

//Constructeurs
tram::tram() :
	d_vitesse{ 0.0 }, d_vitesseItnit{ 0.0 }, d_X{ 0 }, d_Y{ 0 }, d_arret{ nullptr }, d_suivant{ nullptr }, d_EstStop{ false },d_cptStop{0}
{}

tram::tram(float vitesse) :
	d_vitesse{ vitesse }, d_vitesseItnit{vitesse}, d_X{ 0 }, d_Y{ 0 }, d_arret{ nullptr }, d_suivant{ nullptr }, d_EstStop{ false }, d_cptStop{ 0 }
{}

tram::tram(float vitesse, arret* pointeurDerArret) :
	d_vitesse{ vitesse }, d_vitesseItnit{ vitesse }, d_X{ pointeurDerArret->X() }, 
	d_Y{ pointeurDerArret->Y() }, d_arret{ pointeurDerArret },d_suivant{ nullptr }, d_EstStop{ false }, d_cptStop{ 0 }
{}

tram::tram(const tram& tramACopier)
{
	d_vitesse = tramACopier.d_vitesse;
	d_vitesseItnit = tramACopier.d_vitesseItnit;
	d_X = tramACopier.d_X;
	d_Y = tramACopier.d_Y;
	d_arret = tramACopier.d_arret;
	d_suivant = tramACopier.d_suivant;
	d_EstStop = tramACopier.d_EstStop;
	d_cptStop = tramACopier.d_cptStop;
}

//Getter
float tram::vitesse()const
{
	return d_vitesse;
}

float tram::vitesseInit() const
{
	return d_vitesseItnit;
}

arret* tram::getArret()const
{
	return d_arret;
}

float tram::X()
{
	return d_X;
}

float tram::Y()
{
	return d_Y;
}

tram* tram::suivant()
{
	return d_suivant;
}

bool tram::getStop()
{
	return d_EstStop;
}

int tram::GetCpt()
{
	return d_cptStop;
}

//Setter
void tram::setVitesse(float vitesse)
{
	d_vitesse = vitesse;
}

void tram::setArret(arret* pointeurArret)
{
	d_arret = pointeurArret;
	d_X = d_arret->X();
	d_Y = d_arret->Y();
}

void tram::setX(float x)
{
	d_X = x;
}

void tram::setY(float y)
{
	d_Y = y;
}

void tram::setSuivant(tram* suivant)
{
	d_suivant = suivant;
}

void tram::SetStop(const bool bl)
{
	d_EstStop = bl;
}

void tram::ReduceVit()
{
	d_vitesse = d_vitesse/3;
}

void tram::RetourVitInit()
{
	d_vitesse = d_vitesseItnit;
}

void tram::IncrCpt()
{
	d_cptStop++;
}

//Methodes
void tram::defineEquation(arret* arretDepart, arret* arretArrive, const bool sens)
{
	float Coeff = ((arretArrive->Y() - arretDepart->Y()) / (arretArrive->X() - arretDepart->X()));
	cout << Coeff << endl;
	float B = arretArrive->Y() - (Coeff * arretArrive->X());
	if(sens)
	{ 
		//aller
		setX(X() + vitesse());
	}
	else
	{
		//retour
		setX(X() - vitesse());
	}
	
	float Y = (Coeff * X()) + B;
	setY(Y);
}

bool tram::ProcheQuai(arret* suivant)
{

	int limite = 15;

	if(d_arret->X() <= d_arret->GetSuiv()->X() && d_arret->Y() <= d_arret->GetSuiv()->Y())
	{
		if (d_X >= suivant->X() - limite && d_Y >= suivant->Y() - limite)
		{
			return true;
		}
	}
	else
	{
		if (d_X <= suivant->X() + limite && d_Y <= suivant->Y() + limite)
		{
			return true;
		}
	}

	return false;
}

void tram::RenitCpt()
{
	d_cptStop = 0;
}

//Tests :

bool tram::EstEnQuai()
{
	int nb = d_vitesse;
	
	if (d_arret->X() <= d_arret->GetSuiv()->X() && d_arret->Y() <= d_arret->GetSuiv()->Y())
	{
		if (d_X >= d_arret->GetSuiv()->X() - nb && d_Y >= d_arret->GetSuiv()->Y() - nb)
		{
			return true;
		}

	}
	else
	{
		if (d_X <= d_arret->GetSuiv()->X() + nb && d_Y <+ d_arret->GetSuiv()->Y() + nb)
		{
			return true;
		}
	}
	
	return false;
	
}