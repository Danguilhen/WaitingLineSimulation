#include "../headers/Caissier.h"
#include "../headers/FinService.h"
#include <numeric>

Caissier::Caissier(float tempsMoyenService, Banque *banque)
{
    _generateur = new Poisson(tempsMoyenService);
    _banque = banque;
    _nbClients = 0;
    _estLibre = true;
}

/**
 * @brief
 *
 * @return int
 */
int Caissier::nbClients()
{
    return _nbClients;
}

/**
 * @brief
 *
 * @return float
 */
float Caissier::tempsMoyenService()
{
    return std::accumulate(_tempsService.begin(), _tempsService.end(), decltype(_tempsService)::value_type(0)) / _tempsService.size();
}

/**
 * @brief
 *
 * @return float
 */
float Caissier::tauxOccupation()
{
    return std::accumulate(_tempsService.begin(), _tempsService.end(), decltype(_tempsService)::value_type(0)) /
           _banque->dureeReel();
}

/**
 * @brief
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
 * @brief
 *
 * @return true
 * @return false
 */
bool Caissier::estLibre()
{
    return _estLibre;
}

/**
 * @brief
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