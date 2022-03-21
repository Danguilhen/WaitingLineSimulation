#include "../headers/Banque.hpp"
#include "../headers/Caissier.hpp"
#include "../headers/Arrivee.hpp"
using namespace std;

Banque::Banque(float dureePrevue, vector<float> tpsService, float tempsMoyenEntreArrivees)
{
    float interTemps;
    _file = FileAttente();
    float heure = 0;
    while (heure < dureePrevue)
    {
        _evenements.push_back(Arrivee(tempsMoyenEntreArrivees, heure, this));
        heure += interTemps;
    }
    for (int i = 0; i < tpsService.size(); i++)
    {
        _caissiers.push_back(Caissier(tpsService[i], this));
    }

    _dureePrevue = dureePrevue;
}

int Banque::nbCaissiers()
{
    return _caissiers.size();
}

int Banque::nbClients()
{
    int nbClients = 0;
    for (auto caissier = begin(_caissiers); caissier != end(_caissiers); ++caissier)
    {
        nbClients += (*caissier).nbClients();
    }
    return nbClients;
}

Caissier Banque::premierCaissierLibre()
{
    int index = 0;
    while (index < _caissiers.size())
    {
        if (_caissiers.at(index).estLibre())
        {
            return _caissiers.at(index);
        }
        index++;
    }
    return NULL;
}

float Banque::dureePrevue()
{
    return _dureePrevue;
}

float Banque::dureeReel()
{
    return _dureeReel;
}

FileAttente* Banque::getFile()
{
    return &_file;
}

vector<Evenement> Banque::getEvenements()
{
    return _evenements;
}