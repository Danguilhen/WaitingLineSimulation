#include <vector>
#include "Evenement.hpp"
#include "FileAttente.hpp"
#include "SED.hpp"
class Banque : public SED
{
public:
    Banque(float dureePrevue, vector<float> tpsService, float tempsMoyenEntreArrivees);

    int nbCaissiers();
    int nbClients();
    Caissier premierCaissierLibre();
    float dureePrevue();
    float dureeReel();
    FileAttente* getFile();
    vector<Evenement> getEvenements();
    Caissier* getCaissier(int i);

private:
    FileAttente _file;
    float _dureePrevue;
    vector<Caissier> _caissiers;
};