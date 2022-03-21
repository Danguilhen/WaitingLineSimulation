#include <vector>
#include "Evenement.hpp"
#include "FileAttente.hpp"
class Banque
{
public:
    Banque(float dureePrevue, vector<float> tpsService, float tempsMoyenEntreArrivees);

    int nbCaissiers();
    int nbClients();
    Caissier premierCaissierLibre();
    float dureePrevue();
    float dureeReel();
    void simulation();
    FileAttente* getFile();
    vector<Evenement> getEvenements();

private:
    float _dureeReel;
    FileAttente _file;
    float _dureePrevue;
    vector<Caissier> _caissiers;
    vector<Evenement> _evenements;
};