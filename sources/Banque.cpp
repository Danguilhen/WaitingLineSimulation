#include "../headers/Banque.h"
#include "../headers/Caissier.h"
#include "../headers/Arrivee.h"
using namespace std;

Banque::Banque(float dureePrevue, vector<float> tpsService, float tempsMoyenEntreArrivees)
{
    _tpsEntreArrivees = tempsMoyenEntreArrivees;
    //float interTemps;
    _file = FileAttente();
    float heure = Poisson().genererTemps(this->tpsEntreArrivees());
    _evenements.push_back(new Arrivee(heure, this));
    for (int i = 0; i < (int) tpsService.size(); i++)
    {
        _caissiers.emplace_back(Caissier(tpsService[i], this));
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

Caissier *Banque::premierCaissierLibre()
{
    size_t index = 0;
    while (index < _caissiers.size())
    {
        if (_caissiers.at(index).estLibre())
        {
            return &_caissiers.at(index);
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

FileAttente *Banque::getFile()
{
    return &_file;
}

vector<Evenement*> Banque::getEvenements()
{
    return _evenements;
}

Caissier *Banque::getCaissier(int i)
{
    return &_caissiers[i];
}
float Banque::tpsEntreArrivees()
{
    return _tpsEntreArrivees;
}