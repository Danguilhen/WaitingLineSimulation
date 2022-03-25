#include "../headers/Client.h"

/**
 * @file sources/Client.cpp
 * @brief Construit un nouveau client:: Client object
 *
 * @param heureArrivee
 */
Client::Client(float heureArrivee)
{
    _heureArrivee = heureArrivee;
}

/**
 * @file sources/Client.cpp
 * @brief Getter de l'heure d'arrivée du client
 *
 * @return float
 */
float Client::heureArrivee()
{
    return _heureArrivee;
}

/**
 * @file sources/Client.cpp
 * @brief Détruit le Client:: Client object
 *
 */
Client::~Client()
{
}