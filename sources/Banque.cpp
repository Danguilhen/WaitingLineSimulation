#include "../headers/Banque.hpp"
#include "../headers/Caissier.hpp"
#include "../headers/Arrivee.hpp"
using namespace std;

Banque::Banque(float dureePrevue, vector<int> tpsService)
{
    float interTemps;
    _file = new FileAttente();
    float temps = 0;
    while (temps < dureePrevue)
    {
        _evenements.push_back(new Arrivee(_file.tempsEntreArrivees())); // TODO correct entries
        temps += interTemps;
    }
    for (int i = 0; i < tpsService.size(); i++)
    {
        _caissiers.push_back(new Caissier(tpsService[i], _evenements));
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

void Banque::simulation()
{
    Evenement evenement;
    while (!_evenements.empty())
    {
        evenement = _evenements.front();
        _evenements.erase(_evenements.begin());
        evenement.traiter();
    }
    _dureeReel = evenement.heure();
}