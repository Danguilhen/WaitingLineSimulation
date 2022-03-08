#include "Client.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Caissier {
    public :
        Caissier(int tempsTravail);
        float tempsMoyenService();
        int nbClients();
        float tauxOccupation();
        bool estLibre();
        void servir(Client client);
        void attendre();
    private :
        float _tempsTravail;
        int _nbClients;
        bool _estLibre;
        vector<float> _tempsService;
};