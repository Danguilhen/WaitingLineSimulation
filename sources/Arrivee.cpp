#include "../headers/Arrivee.h"
#include "../headers/Banque.h"

/**
 * @file sources/Arrivee.cpp
 * @brief Constructeur de l'objet Arrivee
 * @param heure 
 * @param banque 
 */
Arrivee::Arrivee(float heure, Banque *banque)
{
    _heure = heure;
    _banque = banque;
}

/**
 * @file sources/Arrivee.cpp
 * @brief Traite l'arrivee d'un Client dans la Banque
 * 
 * Dans le cas où l'heure actuelle n'a pas dépassé l'heure prévisionnelle :
 *  S'il y a un Caissier libre, assigne le Client à ce Caissier
 *  Sinon, ajoute le Client à la file d'attente
 * 
 */
void Arrivee::traiter()
{
    if (_banque->heure() < _banque->dureePrevue())
    {
        float heure = _banque->tpsEntreArrivees() + _heure;
        _banque->setHeure(heure);
        Arrivee *arrivee = new Arrivee(heure, _banque);
        _banque->getEvenements().push_back(arrivee);
    }
    if (_banque->premierCaissierLibre() != NULL)
    {
        _banque->premierCaissierLibre()->servir(new Client(_heure));
    }
    else
    {
        _banque->getFile()->ajouter(new Client(_heure));
    }
}