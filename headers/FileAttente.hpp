#pragma once 
#include <vector>
#include "Client.hpp"


class FileAttente {
    public :
        FileAttente();

        float tempsEntreArrivees();
        float longueurMoyenne();
        int longueurMax();
        float tempsMoyenAttente();
        void ajouter(Client c);
        bool estVide();
        Client retirer();

    private :
        int _nbClients;
        int _longueurMax;
        double _longueurMoyenne;
        double _tempsMoyenAttente;
        vector<Client> _file;
};