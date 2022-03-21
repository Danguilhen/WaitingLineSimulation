class SED
{
    public :
        float ajouter(Evenement evenement);
        void lancer();
    protected :
        float _dureeReel;
        vector<Evenement> _evenements;
};