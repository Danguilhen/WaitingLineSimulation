#ifndef CLIENT
#define CLIENT

class Client {
    public :
        Client(float heureArrivee);
        float heureArrivee();
        ~Client();
    private :
        float _heureArrivee;
};

#endif