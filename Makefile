# Fichiers sources
SRC = sources/Arrivee.cpp \
sources/Banque.cpp \
sources/Caissier.cpp \
sources/Client.cpp \
sources/Evenement.cpp \
sources/FileAttente.cpp \
sources/FinService.cpp \
sources/SED.cpp \
sources/Poisson.cpp \
simu.cpp

OBJ = $(SRC:.cpp=.o)


main : $(OBJ) \
        g++ -o main $(OBJ)

sources/Arrivee.o : headers/Arrivee.h headers/Client.h headers/Poisson.h headers/Caissier.h
sources/Banque.o : headers/Banque.h headers/Caissier.h headers/Arrivee.h
sources/Caissier.o : headers/Caissier.h headers/FinService.h
sources/Client.o : headers/Client.h
sources/Evenement.o : headers/Evenement.h
sources/FileAttente.o : headers/Client.h headers/FileAttente.h
sources/FinService.cpp : headers/FinService.h headers/Poisson.h headers/Caissier.h
sources/SED.cpp : headers/SED.h headers/Evenement.h
sources/Poisson.cpp : headers/Poisson.h
simu.cpp : headers/Banque.h
