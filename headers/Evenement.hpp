#ifndef EVENEMENT
#define EVENEMENT

class Evenement {
    public :
        float heure();
        virtual void traiter();
    protected:
        float _heure;
};

#endif