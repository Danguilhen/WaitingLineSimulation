#include "../headers/Arrivee.h"

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
        Arrivee* arrivee = new Arrivee(_heure, _banque);
        _banque->getEvenements().push_back(arrivee);
        cout << _banque->getEvenements().size() << endl;
    }
    if (_banque->premierCaissierLibre() != NULL) // Must be modify
    {
        cout << "Deuxième if" << endl;
        _banque->premierCaissierLibre()->servir(new Client(_heure));
        cout << "Deuxième if partie deux" << endl;
    }
    else
    {
        cout << "3 if" << endl;
        _banque->getFile()->ajouter(new Client(_heure));
    }
}