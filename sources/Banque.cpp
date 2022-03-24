#include "../headers/Banque.h"

Banque::Banque(float dureePrevue, vector<float> tpsService, float tempsMoyenEntreArrivees)
{
    _tpsEntreArrivees = tempsMoyenEntreArrivees;
    Caissier *caissier;
    _file = new FileAttente(this); 
    float heure = Poisson().genererTemps(this->tpsEntreArrivees());
    _evenements.push_back(new Arrivee(heure, this));
    for (int i = 0; i < (int) tpsService.size(); i++)
    {   
        caissier = new Caissier(tpsService[i], this);
        _caissiers.push_back(*caissier);
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
    Caissier *caissier;
    while (index < _caissiers.size())
    {
        if (_caissiers.at(index).estLibre())
        {
            cout << "Dans if de caissier libre" << endl;
            caissier = &_caissiers.at(index);
            cout << "caissier at index réussi" << endl;
            return caissier; //TODO : corriger
        }
        index++;
    }
    cout << "Avant de return null" << endl;
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
    return _file;
}

vector<Evenement*>& Banque::getEvenements()
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