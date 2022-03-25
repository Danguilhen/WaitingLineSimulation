
#include "../headers/FileAttente.h"
#include "../headers/Banque.h"
#include <numeric>

FileAttente::FileAttente(Banque *banque)
{
    _ancienneHeure = 0;
    _aire = 0;
    _banque = banque;
    _longueurMax = 0;
    _nbClients = 0;
}

int FileAttente::longueurMax()
{
    return _longueurMax;
}

float FileAttente::longueurMoyenne()
{
    return _aire / _banque->heure();
}

float FileAttente::tempsMoyenAttente()
{
    return std::accumulate(_tempsAttente.begin(), _tempsAttente.end(), decltype(_tempsAttente)::value_type(0)) / _tempsAttente.size();
}

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

bool FileAttente::estVide()
{
    return _file.empty();
}

Client *FileAttente::retirer()
{
    _aire += (_banque->heure() - _ancienneHeure) * _file.size();
    _ancienneHeure = _banque->heure();
    Client *client = _file.front();
    _tempsAttente.push_back(_banque->heure() - client->heureArrivee());
    _file.erase(_file.begin());
    return client;
}
