#include "Caissier.hpp"
#include <vector>

class Banque {
    public :
        Banque(float dureePrevue);

        int nbCaissiers();
        int nbClients();
        Caissier premierCaissierLibre();
        float dureePrevue();
        float dureeReel();

    private :
        float _dureePrevue;
        vector<Caissier> _caissiers;
};