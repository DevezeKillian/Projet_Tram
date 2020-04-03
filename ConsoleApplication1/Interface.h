#ifndef INTER_H
#define INTER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "tram.h"
#include "arret.h"
#include "ListeChaine.h"
#include "listeChaineTram.h"
#include "LectureFichier.h"
#include <fstream>

class Interface
{
private:
	sf::RenderWindow* d_window;
	arret* d_a;
	sf::Clock dtClock;
	sf::Event sfEvent;
	float dt;
public:
	Interface();
	virtual ~Interface();
	void CreationLigne(vector<ListeChaine*>& tabArrets);
	void CreationTram();
	void deplacement(vector<ListeChaine*>& tabArrets, vector<listeChaineTram*>& tabTrams);
	void initWindow();
	void Run();
	void updateSFMLEvents();
	sf::RenderWindow* GetWindow();
};

#endif