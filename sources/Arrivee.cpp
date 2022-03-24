#include "../headers/Arrivee.h"
#include "../headers/Banque.h"

Arrivee::Arrivee(float heure, Banque *banque)
{
    _heure = heure;
    _banque = banque;
}

void Arrivee::traiter()
{
    std::cout << "Je traite dans arrivée" << std::endl;
    if (_banque->heure() < _banque->dureePrevue())
    {
        std::cout << _banque->getEvenements().size() << std::endl;
        Arrivee *arrivee = new Arrivee(_heure, _banque);
        _banque->getEvenements().push_back(arrivee);
        std::cout << _banque->getEvenements().size() << std::endl;
    }
    if (_banque->premierCaissierLibre() != NULL) // Must be modify
    {
        std::cout << "Deuxième if" << std::endl;
        _banque->premierCaissierLibre()->servir(new Client(_heure));
        std::cout << "Deuxième if partie deux" << std::endl;
    }
    else
    {
        std::cout << "3 if" << std::endl;
        _banque->getFile()->ajouter(new Client(_heure));
    }
}