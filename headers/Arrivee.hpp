#ifndef ARRIVEE
#define ARRIVEE

#include "Evenement.hpp"
#include "Banque.hpp"

class Arrivee : public Evenement
{
public:
    Arrivee(float tempsMoyenEntreArrivees, float heure, Banque *banque);
    void traiter();
    private :
        Banque* _banque;
};

#endif