#include <stdio.h>
#include "prototype.h"

void lireEntreeUtilisateur(char ip[], char masque[]) {
    printf("Entrez l'adresse IP (format xxx.xxx.xxx.xxx) : ");
    scanf("%15s", ip);
    printf("Entrez le masque de sous-réseau (format xxx.xxx.xxx.xxx) : ");
    scanf("%15s", masque);
}

int estValideIP(char ip[]) {
    int nombre = 0, points = 0;

    for (int i = 0; ip[i] != '\0'; i++) {
        if (ip[i] >= '0' && ip[i] <= '9') {
            nombre = nombre * 10 + (ip[i] - '0');
            if (nombre > 255) return 0; 
        } else if (ip[i] == '.') {
            points++;
            if (nombre < 0 || nombre > 255) return 0; 
            nombre = 0; 
        } else {
            return 0; 
        }
    }

    return points == 3;
}


int estValideMasqueSousReseau(char masque[]) {
    int masques[] = {255, 254, 252, 248, 240, 224, 192, 128, 0};
    int nombre = 0, points = 0, trouve = 0;

    for (int i = 0; masque[i] != '\0'; i++) {
        if (masque[i] >= '0' && masque[i] <= '9') {
            nombre = nombre * 10 + (masque[i] - '0');
        } else if (masque[i] == '.') {
            trouve = 0;
            for (int j = 0; j < 9; j++) {
                if (nombre == masques[j]) {
                    trouve = 1;
                    break;
                }
            }
            if (!trouve) return 0; 
            points++;
            nombre = 0;
        } else {
            return 0; 
        }
    }

    return points == 3;
}


void afficherResultat(int valideIP, int valideMasque) {
    if (!valideIP) {
        printf("Adresse IP invalide.\n");
    }
    if (!valideMasque) {
        printf("Masque de sous-réseau invalide.\n");
    }
    if (valideIP && valideMasque) {
        printf("Adresse IP et masque de sous-réseau valides.\n");
    }
}
