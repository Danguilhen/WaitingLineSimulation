#include "Evenement.hpp"

class Arrivee : public Evenement
{
public:
    Arrivee(float tempsMoyenEntreArrivees, float heure, Banque *banque);
    void traiter();
};