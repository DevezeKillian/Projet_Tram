#include <iostream>
#include "arret.h"
/**
	Author : Arthur BIALEK
	Version : 1.0
*/

using namespace std;

//Constructeurs
arret::arret() :
	d_nom{ "" }, d_X{ 0 }, d_Y{ 0 }, d_suivant{ nullptr }, d_precedent{ nullptr }
{}

arret::arret(string nom) :
	d_nom{ nom }, d_X{ 0 }, d_Y{ 0 }, d_suivant{ nullptr }, d_precedent{ nullptr }
{}

arret::arret(string nom, int X, int Y) :
	d_nom{ nom }, d_X{ X }, d_Y{ Y }, d_suivant{ nullptr }, d_precedent{ nullptr }
{}

//Getters
std::string arret::nom()const {
	return d_nom;
}

float arret::X() {
	return d_X;
}

float arret::Y() {
	return d_Y;
}

arret* arret::GetSuiv()
{
	return d_suivant;
}

//Setters
void arret::setNom(std::string nom) {
	d_nom = nom;
}

void arret::setX(int X) {
	d_X = X;
}

void arret::setY(int Y) {
	d_Y = Y;
}

void arret::setSuiv(arret* a)
{
	d_suivant = a;
}
