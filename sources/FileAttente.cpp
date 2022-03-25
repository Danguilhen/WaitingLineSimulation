
#include "../headers/FileAttente.h"
#include "../headers/Banque.h"
#include <numeric>

/**
 * @file sources/FileAttente.cpp
 * @brief Contructeur d'un nouveau File Attente:: File Attente object
 * @param banque
 * @return FileAttente
 */
FileAttente::FileAttente(Banque *banque)
{
    _ancienneHeure = 0;
    _aire = 0;
    _banque = banque;
    _longueurMax = 0;
    _nbClients = 0;
}

/**
 * @file sources/FileAttente.cpp
 * @brief getter de longueurMax
 * 
 * @return int
 */
int FileAttente::longueurMax()
{
    return _longueurMax;
}

/**
 * @file sources/FileAttente.cpp
 * @brief calcule la longueur moyenne de la file d'attente
 * 
 * @return float
 */
float FileAttente::longueurMoyenne()
{
    return _aire / _banque->heure();
}

/**
 * @file sources/FileAttente.cpp
 * @brief calcule de temps moyen d'attente d'un Client dans la file
 *
 * @return float
 */
float FileAttente::tempsMoyenAttente()
{
    return std::accumulate(_tempsAttente.begin(), _tempsAttente.end(), decltype(_tempsAttente)::value_type(0)) / _tempsAttente.size();
}

/**
 * @file sources/FileAttente.cpp
 * @brief ajoute un Client à la file d'attente et met à jour les paramètres _aire, _ancienneHeure, _longueurMax
 *
 * @param client
 */
void FileAttente::ajouter(Client *client)
{
    _aire += (_banque->heure() - _ancienneHeure) * _file.size();
    _ancienneHeure = _banque->heure();
    _file.push_back(client);
    if ((int)_file.size() > _longueurMax)
    {
        _longueurMax = (int)_file.size();
    }
}

/**
 * @file sources/FileAttente.cpp
 * @brief vérifie si le file est vide
 *
 * @return true
 * @return false
 */
bool FileAttente::estVide()
{
    return _file.empty();
}

/**
 * @file sources/FileAttente.cpp
 * @brief retire un Client de la file et met à jour les paramètre _aire, _ancienneHeure, _longueurMax
 *
 * @return Client*
 */
Client *FileAttente::retirer()
{
    _aire += (_banque->heure() - _ancienneHeure) * _file.size();
    _ancienneHeure = _banque->heure();
    Client *client = _file.front();
    _tempsAttente.push_back(_banque->heure() - client->heureArrivee());
    _file.erase(_file.begin());
    return client;
}
