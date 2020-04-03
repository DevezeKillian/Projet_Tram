#include "tram.h"

#ifndef LISTE_CHAINE_TRAM_H_INCLUDED
#define LISTE_CHAINE_TRAM_H_INCLUDED

/**
    Author : Hugo STAEDELIN
    Version : 1.0
*/
class listeChaineTram
{
    friend std::ostream& operator<<(std::ostream& os, const listeChaineTram& lc);
    public:
        listeChaineTram();
        ~listeChaineTram();
        void ajout(tram* noTram);
        tram* operator[](int i);
        tram* RenvoieTete();
    private:
        tram* d_tete;
};

std::ostream& operator<<(std::ostream& os, const listeChaineTram& l);

#endif // LISTE_CHAINE_TRAM_H_INCLUDED
