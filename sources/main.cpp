#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//g++ -o main main.cpp
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

    cout << dureePrevue << endl;
    cout << nombreCaissiers << endl;
    for (int i = 0; i<nombreCaissiers; i++)
        cout << tempsMoyenService[i] <<endl;
    cout << tempsEntreArrivees << endl;
}