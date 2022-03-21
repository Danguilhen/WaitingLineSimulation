#include "Evenement.hpp"
#include "Caissier.hpp"
class FinService : public Evenement
{
public:
    FinService(Caissier *caissier);
    void traiter();

private:
    Caissier &_caissier;
};