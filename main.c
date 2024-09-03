#include "prototype.h"

int main() {
    char ip[16], masqueSousReseau[16];

    
    lireEntreeUtilisateur(ip, masqueSousReseau);

    
    int valideIP = estValideIP(ip);
    int valideMasque = estValideMasqueSousReseau(masqueSousReseau);

    afficherResultat(valideIP, valideMasque);

    return 0;
}
