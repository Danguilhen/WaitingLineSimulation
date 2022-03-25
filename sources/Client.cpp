#include "../headers/Client.h"

/**
 * @brief Construit un nouveau client:: Client object
 *
 * @param heureArrivee
 */
Client::Client(float heureArrivee)
{
    _heureArrivee = heureArrivee;
}

/**
 * @brief Getter de l'heure d'arrivée du client
 *
 * @return float
 */
float Client::heureArrivee()
{
    return _heureArrivee;
}

/**
 * @brief Détruit le Client:: Client object
 *
 */
Client::~Client()
{
}