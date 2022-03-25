#include "../headers/Banque.h"
#include "../headers/FileAttente.h"
#include "../headers/Poisson.h"

Banque::Banque(float dureePrevue, std::vector<float> tpsService, float tempsMoyenEntreArrivees)
{
    _generateur = new Poisson(tempsMoyenEntreArrivees);
    Caissier *caissier;
    _file = new FileAttente(this);
    float heure = this->tpsEntreArrivees();
    Arrivee *arrivee = new Arrivee(heure, this);
    _evenements.push_back(arrivee);
    for (int i = 0; i < (int)tpsService.size(); i++)
    {
        caissier = new Caissier(tpsService[i], this);
        _caissiers.push_back(caissier);
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
        nbClients += (*caissier)->nbClients();
    }
    return nbClients;
}

Caissier *Banque::premierCaissierLibre()
{
    size_t index = 0;
    Caissier *caissier;
    while (index < _caissiers.size())
    {
        if (_caissiers.at(index)->estLibre())
        {
            caissier = _caissiers.at(index);
            return caissier; // TODO : corriger
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
    return _heure;
}

FileAttente *Banque::getFile()
{
    return _file;
}

std::vector<Evenement *> &Banque::getEvenements()
{
    return _evenements;
}

Caissier *Banque::getCaissier(int i)
{
    return _caissiers[i];
}
float Banque::tpsEntreArrivees()
{
    return _generateur->genererTemps();
}