#include "../headers/Caissier.h"
#include "../headers/FinService.h"
#include <numeric>

/**
 * @file sources/Caissier.cpp
 * @brief Construct a new Caissier:: Caissier object
 *
 * @param tempsMoyenService
 * @param banque
 */
Caissier::Caissier(float tempsMoyenService, Banque *banque)
{
    _generateur = new Poisson(tempsMoyenService);
    _banque = banque;
    _nbClients = 0;
    _estLibre = true;
}

/**
 * @file sources/Caissier.cpp
 * @brief Getter du nombre de clients servis par le caissier
 *
 * @return int
 */
int Caissier::nbClients()
{
    return _nbClients;
}

/**
 * @file sources/Caissier.cpp
 * @brief Getter du temps moyen de service du caissier
 *
 * @return float
 */
float Caissier::tempsMoyenService()
{
    return std::accumulate(_tempsService.begin(), _tempsService.end(), decltype(_tempsService)::value_type(0)) / _tempsService.size();
}

/**
 * @file sources/Caissier.cpp
 * @brief Getter du taux d'occupation du caissier
 *
 * @return float
 */
float Caissier::tauxOccupation()
{
    return std::accumulate(_tempsService.begin(), _tempsService.end(), decltype(_tempsService)::value_type(0)) /
           _banque->dureeReel();
}

/**
 * @file sources/Caissier.cpp
 * @brief Libère le caissier
 *
 */
void Caissier::devientLibre()
{
    if (_banque->getFile()->estVide()) // file d'attente est vide TODO
    {
        _estLibre = true;
    }
    else
    {
        servir(_banque->getFile()->retirer());
    }
}

/**
 * @file sources/Caissier.cpp
 * @brief Getter de l'état d'occupation du caissier
 *
 * @return true
 * @return false
 */
bool Caissier::estLibre()
{
    return _estLibre;
}

/**
 * @file sources/Caissier.cpp
 * @brief Service d'un client
 *
 * @param client
 */
void Caissier::servir(Client *client)
{
    delete client;
    float heure = _generateur->genererTemps();
    _tempsService.push_back(heure);
    _nbClients += 1;
    _estLibre = false;
    FinService *finService = new FinService(this, heure);
    _banque->getEvenements()
        .push_back(finService);
}