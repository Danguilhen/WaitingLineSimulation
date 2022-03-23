#include "../headers/SED.h"
#include "../headers/Evenement.h"
#include <iostream>

void SED::ajouter(Evenement* evenement)
{
    _evenements.push_back(evenement);
}

void SED::lancer()
{
    int index;
    float min;
    Evenement* evenement;

    while (!_evenements.empty())
    {
        index = 0;
        min = _evenements[0]->heure();
        for (int i = 0; i < (int) _evenements.size(); i++)
        {
            cout << "Coucou" << endl;
            if (_evenements[i]->heure() < min)
            {
                min = _evenements[i]->heure();
                index = i;
            }
        }
        evenement = _evenements.at(index);
        _evenements.erase(_evenements.begin() + index);
        evenement->traiter();
    }
    _dureeReel = evenement->heure();
}

float SED::heure()
{
    return _heure;
}