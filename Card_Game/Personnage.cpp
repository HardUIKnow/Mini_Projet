#include "Personnage.h"

Personnage::Personnage(int pv, int atk, int def, double spd) 
    : pointsDeVie(pv), attaque(atk), defense(def), vitesse(spd), energie(0) {}

void Personnage::frappePreventive() {
    std::cout << "Frappe préventive : Attaque de base inflige " << attaque << " dégâts." << std::endl;
    gagnerEnergie(25);
}

void Personnage::blast() {
    std::cout << "Blast : Attaque améliorée inflige " << 1.5 * attaque << " dégâts." << std::endl;
    gagnerEnergie(35);
}

void Personnage::attaqueDelta() {
    if (energie >= 100) {
        std::cout << "Attaque Delta : Inflige 3.5x attaque, consomme toute l'énergie." << std::endl;
        perdreEnergie(100);
    } else {
        std::cout << "Pas assez d'énergie pour utiliser l'Attaque Delta !" << std::endl;
    }
}

void Personnage::gagnerEnergie(int montant) {
    energie = std::min(100, energie + montant);
    std::cout << "Gagne " << montant << " points d'énergie. Énergie actuelle : " << energie << std::endl;
}

void Personnage::perdreEnergie(int montant) {
    energie = std::max(0, energie - montant);
    std::cout << "Perd " << montant << " points d'énergie. Énergie actuelle : " << energie << std::endl;
}
