#include "SED.hpp"
#include "Evenement.hpp"

void SED::lancer()
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