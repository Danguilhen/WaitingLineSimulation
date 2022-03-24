#include <ctype.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "headers/Banque.h"

//  ./simu -dp 10 -nc 3 -ts 1 1 1 -ta 0.5
//  g++ -o simu simu.cpp
int main(int argc, char **argv)
{
    float dureePrevue;
    int nombreCaissiers = 0;
    std::vector<float> tempsMoyenService;
    float tempsEntreArrivees;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-dp") == 0) // durée prévue
            dureePrevue = std::stoi(argv[i + 1]);
        else if (strcmp(argv[i], "-nc") == 0) // nombre de caissiers
            nombreCaissiers = std::stoi(argv[i + 1]);
        else if (strcmp(argv[i], "-ts") == 0) // temps de service
            for (int j = 1; j < nombreCaissiers + 1; j++)
                tempsMoyenService.push_back(std::stof(argv[i + j]));
        else if (strcmp(argv[i], "-ta") == 0) // temps entre arrivée
            tempsEntreArrivees = std::stof(argv[i + 1]);
    }

    Banque banque(dureePrevue, tempsMoyenService, tempsEntreArrivees);
    banque.lancer();
    std::cout << "Durée réelle de simulation : " << banque.dureeReel() << '\n';
    std::cout << "Nombre total de clients servis :" << banque.nbClients() << '\n';
    for (int i = 0; i < nombreCaissiers; i++)
    {
        std::cout << "\nCaissier " << i + 1 << " :" << '\n';
        std::cout << "  Nombre de clients servis : " << banque.getCaissier(i)->nbClients() << '\n';
        std::cout << "  Taux d'occupation : " << banque.getCaissier(i)->tauxOccupation() << '\n';
        std::cout << "  Taux moyen de service : " << banque.getCaissier(i)->tempsMoyenService() << '\n';
    }
    std::cout << "\nFile d'attente :\n  Longueur moyenne : " << banque.getFile()->longueurMoyenne() << '\n';
    std::cout << "  Longueur maximale : " << banque.getFile()->longueurMax() << '\n';
    std::cout << "  Temps moyen d'attente : " << banque.getFile()->tempsMoyenAttente() << '\n';
}
