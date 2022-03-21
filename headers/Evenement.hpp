#pragma once 

class Evenement {
    public :
        float heure();
        virtual void traiter();
    protected:
        float _heure;
};