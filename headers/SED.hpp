class SED
{
    public :
        void ajouter(Evenement evenement);
        void lancer();
    protected :
        float _dureeReel;
        vector<Evenement> _evenements;
};