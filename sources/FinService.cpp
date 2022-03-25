#include "../headers/FinService.h"
#include <iostream>

/**
 * @file sources/FinService.cpp
 * @brief Construct a new Fin Service:: Fin Service object
 *
 * @param caissier
 * @param heure
 */
FinService::FinService(Caissier *caissier, float heure)
{
    _caissier = caissier;
    _heure = heure;
}

/**
 * @file sources/FinService.cpp
 * @brief Traite la fin de service
 *
 * Rend le caissier de l'évenement fin de service libre
 * 
 */
void FinService::traiter()
{
    _caissier->devientLibre();
}