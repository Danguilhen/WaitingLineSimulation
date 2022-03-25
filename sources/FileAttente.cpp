
#include "../headers/FileAttente.h"
#include "../headers/Banque.h"
#include <numeric>

/**
 * @brief Construct a new File Attente:: File Attente object
 *
 * @param banque
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
 * @brief
 *
 * @return int
 */
int FileAttente::longueurMax()
{
    return _longueurMax;
}

/**
 * @brief
 *
 * @return float
 */
float FileAttente::longueurMoyenne()
{
    return _aire / _banque->heure();
}

/**
 * @brief
 *
 * @return float
 */
float FileAttente::tempsMoyenAttente()
{
    return std::accumulate(_tempsAttente.begin(), _tempsAttente.end(), decltype(_tempsAttente)::value_type(0)) / _tempsAttente.size();
}

/**
 * @brief
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
 * @brief
 *
 * @return true
 * @return false
 */
bool FileAttente::estVide()
{
    return _file.empty();
}

/**
 * @brief
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
