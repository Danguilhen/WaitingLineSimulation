#include "../headers/SED.h"
#include <iostream>

/**
 * @file sources/SED.cpp
 * @brief Ajouter un évènement à la simulation
 *
 * @param evenement
 */
void SED::ajouter(Evenement *evenement)
{
    _evenements.push_back(evenement);
}

/**
 * @file sources/SED.cpp
 * @brief Réalise une simulation du service de la banque
 *
 */
void SED::lancer()
{
    int index;
    float min;
    Evenement *evenement;

    while (!_evenements.empty())
    {
        index = 0;
        min = _evenements[0]->heure();
        for (int i = 0; i < (int)_evenements.size(); i++)
        {
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
}

/**
 * @file sources/SED.cpp
 * @brief Getter de l'heure actuelle
 *
 * @return float
 */
float SED::heure()
{
    return _heure;
}

/**
 * @file sources/SED.cpp
 * @brief Setter de l'haure actuelle
 *
 * @param heure
 */
void SED::setHeure(float heure)
{
    _heure = heure;
}