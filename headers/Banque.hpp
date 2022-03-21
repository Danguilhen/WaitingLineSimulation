#include <vector>
#include "Evenement.hpp"
#include "FileAttente.hpp"
class Banque
{
public:
    Banque(float dureePrevue, vector<int> tpsService);

    int nbCaissiers();
    int nbClients();
    Caissier premierCaissierLibre();
    float dureePrevue();
    float dureeReel();
    void simulation();

private:
    float _dureeReel;
    FileAttente _file;
    float _dureePrevue;
    vector<Caissier> _caissiers;
    vector<Evenement> _evenements;
};