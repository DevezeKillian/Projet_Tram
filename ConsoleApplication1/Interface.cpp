#include <SFML/Graphics.hpp>
#include "Interface.h"
#include "ListeChaine.h"
#include <fstream>
#include <vector>

Interface::Interface()
{
	initWindow();
}

Interface::~Interface()
{
	delete d_window;
}

void Interface::CreationLigne(vector<ListeChaine*>& tabArrets)
{
	
	for (int k = 0; k < tabArrets.size();++k)
	{
		arret* tmp = tabArrets[k]->RenvoieTete();
		int cpt = tabArrets[k]->LongueurListe() / 2;
		for (int l = 0; l < cpt + 1; l++)
		{
			sf::CircleShape shape(5.f);
			shape.setFillColor(sf::Color::Yellow);
			shape.setPosition(sf::Vector2f(tmp->X(), tmp->Y()));
			d_window->draw(shape);
			tmp = tmp->GetSuiv();
		}
		tmp = tabArrets[k]->RenvoieTete();
		for (int j = 0; j < cpt; j++)
		{

			arret* suivc = tmp->GetSuiv();

			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(tmp->X(), tmp->Y())),
				sf::Vertex(sf::Vector2f(suivc->X(), suivc->Y()))
			};
			d_window->draw(line, 2, sf::Lines);
			tmp = tmp->GetSuiv();
		}
	}
}



void Interface::deplacement(vector<ListeChaine*>& tabArrets, vector<listeChaineTram*>& tabTrams)
{

	sf::CircleShape Tram(2.f);
	Tram.setFillColor(sf::Color::Red);

	// définit un contour orange de 10 pixels d'épaisseur
	Tram.setOutlineThickness(2.f);
	Tram.setOutlineColor(sf::Color::Yellow);
	tram* t = tabTrams[0]->RenvoieTete();
	Tram.setPosition(sf::Vector2f(t->X(), t->Y()));
	d_window->draw(Tram);
	/*
	int cpt = 0;
	int NbArret = tabArrets[0]->LongueurListe();
	NbArret = NbArret / 2;
	*/
	tram* tmpTram = t;
	for (int d = 0; d < 2; ++d)
	{
		tmpTram->setArret(tabArrets[0]->RenvoieTete());
		tmpTram = tmpTram->suivant();
	}

	while (1)
	{

		
		tmpTram = t;
		for (int d = 0; d < 2; ++d)
		{
			arret* tmp = tmpTram->getArret();
			arret* suivc = tmp->GetSuiv();
		
			//cout << "---------------------------" << tmpTram->vitesse() << "------------------------------" << endl;

			
			if (tmpTram->ProcheQuai(suivc) && tmpTram->vitesse() != tmpTram->vitesseInit())
			{
				tmpTram->ReduceVit();
			}
			else
			{
				tmpTram->RetourVitInit();

			}
			if (tmpTram->getStop() == false)
			{
				if (tmp->X() <= suivc->X())
				{
					tmpTram->defineEquation(tmp, suivc, true);
				}
				else
				{
					tmpTram->defineEquation(tmp, suivc, false);
				}

			}
			else
			{
				tmpTram->IncrCpt();
			}


			if (tmpTram->EstEnQuai())
			{
				tmpTram->SetStop(true);

				if (tmpTram->GetCpt() > 1)
				{
					tmpTram->RenitCpt();
					tmpTram->setArret(suivc);
					tmpTram->SetStop(false);
				}
			}

			tmpTram = tmpTram->suivant();


		}
		//cout<<"---------------------------" << t->X()<<"------------------------------"<<endl;


		tmpTram = t;
		for (int d = 0; d < 3; ++d)
		{
			Tram.setPosition(tmpTram->X(), tmpTram->Y());
			d_window->draw(Tram);
			tmpTram = tmpTram->suivant();
		}
		d_window->setFramerateLimit(60);
		CreationLigne(tabArrets);
		d_window->display();
		d_window->clear();
		Sleep(200);
	}
}

void inline Interface::initWindow()
{
	d_window = new sf::RenderWindow(sf::VideoMode(800, 800), "Tramways");
}

void Interface::Run()
{
	vector<ListeChaine*> tabArrets;
	vector<listeChaineTram*> tabTrams;

	LectureFichier lectureArrets("CoordoneesLignes.txt");
	lectureArrets.chainageArret(tabArrets);

	LectureFichier lectureTrams("TramsLignes.txt");
	lectureTrams.chainageTram(tabTrams, tabArrets.size());

	while (d_window->isOpen())
	{
		updateSFMLEvents();
		deplacement(tabArrets, tabTrams);
	}
}

void Interface::updateSFMLEvents()
{
	while (d_window->pollEvent(sfEvent))
	{
		//Si l'événement "close" se produit la fenetre se ferme
		if (sfEvent.type == sf::Event::Closed)
			d_window->close();
	}
}

sf::RenderWindow* Interface::GetWindow()
{
	return d_window;
}