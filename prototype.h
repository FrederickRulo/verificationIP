#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

// Fonction pour vérifier si une adresse IP est valide
int estValideIP(char ip[]);

// Fonction pour vérifier si un masque de sous-réseau est valide
int estValideMasqueSousReseau(char masque[]);

// Fonction pour lire les entrées de l'utilisateur
void lireEntreeUtilisateur(char ip[], char masque[]);

// Fonction pour afficher le résultat
void afficherResultat(int valideIP, int valideMasque);

#endif
