# Simulation d'agence banquaire

Ce projet est une simulation de banque avec des caissiers qui servent des clients, qui attendent dans une file d'attente s'il n'y a pas de caissier de libre.

## Construction et execution du projet

Dans un terminal ouvert à la source du projet, exécuter la commande suivante :

```bash
make
```

Voilà un exemple de commande pour éxecuter le code :

```bash
./simu -dp 10 -nc 3 -ts 5 8 3 -ta 0.7
```

Et un autre :
```bash
./simu -dp 60 -nc 5 -ts 5 8 3 9 2 -ta 0.1
```

Signification des paramètres qu'il faut renseigner : \
-dp correspond à la **durée prévue**. Sa valeur par défaut est 10.\
-nc correspond aux **nombres de caissiers**. Sa valeur par défaut est 0.\
-ts correspond au **temps de service** des caissiers. Il faut donc renseigner autant de temps de services que vous avez renseigné de caissiers. \
-ta correspond au **temps d'arrivée** entre chaque client. Sa valeur par défaut est 0.5.
