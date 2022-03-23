#include "../headers/Arrivee.h"
#include "../headers/Client.h"
#include <vector>
#include "../headers/Caissier.h"
#include <iostream>
using namespace std;

Arrivee::Arrivee(float heure, Banque *banque)
{
    _heure = heure;
    _banque = banque;
}

void Arrivee::traiter()
{
    cout << "Je traite dans arrivée" << endl;
    if (_banque->heure() < _banque->dureePrevue())
    {
        cout << _banque->getEvenements().size() << endl;
        _banque->getEvenements().push_back(new Arrivee(_heure, _banque));
        cout << _banque->getEvenements().size() << endl;
    }
    if (_banque->premierCaissierLibre() != NULL) // Must be modify
    {
        _banque->premierCaissierLibre()->servir(Client(_heure));
    }
    else
    {
        _banque->getFile()->ajouter(Client(_heure));
    }
}