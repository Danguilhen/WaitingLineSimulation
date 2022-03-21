#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "../headers/Banque.hpp"
using namespace std;

//  ./simu -dp 10 -nc 3 -ts 1 1 1 -ta 0.5
//  g++ -o main main.cpp
int main(int argc, char **argv)
{
    int dureePrevue;
    int nombreCaissiers = 0;
    vector<float> tempsMoyenService;
    float tempsEntreArrivees;
    for(int i=1; i<argc; i++)
    {       
        if (strcmp(argv[i], "-dp") == 0) //durée prévue
            dureePrevue = stoi(argv[i+1]);
        else if (strcmp(argv[i], "-nc") == 0) //nombre de caissiers
            nombreCaissiers = stoi(argv[i+1]);
        else if (strcmp(argv[i], "-ts") == 0) //temps de service
            for(int j=1; j<nombreCaissiers+1; j++)
                tempsMoyenService.push_back(stof(argv[i+j]));
        else if (strcmp(argv[i], "-ta") == 0)//temps entre arrivée
            tempsEntreArrivees = stof(argv[i+1]);
    }
    Banque banque(dureePrevue, tempsMoyenService, tempsEntreArrivees);
    banque.lancer();
    cout << "Durée réelle de simulation : " << banque.dureeReel() << endl;
    cout << "Nombre total de clients servis :" << banque.nbClients() << endl;
    for(int i=0; i<nombreCaissiers; i++)
    {
        cout << "\nCaissier " << i+1 << " :" << endl;
        cout << "Nombre de clients servis : " << banque.getCaissier(i)->nbClients() << endl;
        cout << "Taux d'occupation : " << banque.getCaissier(i)->tauxOccupation() << endl;
    }
    cout << "Longueur moyenne de la file :" << banque.getFile()->longueurMoyenne() << endl;
    cout << "Longueur maximale de la file d'attente : " << banque.getFile()->longueurMax() << endl;
    cout << "Temps moyen d'attente dans la file d'attente : " << banque.getFile()->tempsMoyenAttente() <<endl;
}
