#include "Evenement.hpp"

class SED {
    public :
        void lancer();
        void ajouter(Evenement evenement);
        float heure();
    private :
        Evenement *evenements;
};