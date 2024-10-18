#include "Berserker.h"

Berserker::Berserker(int pv, int atk, int def, double spd) 
    : Personnage(pv, atk, def, spd) {}

void Berserker::frappePunitive() {
    int damage = static_cast<int>(0.3 * pointsDeVie);
    pointsDeVie -= static_cast<int>(0.1 * pointsDeVie);  // Consomme 10% des PV
    std::cout << "Frappe punitive : Inflige " << damage << " dégâts et consomme 10% des PV." << std::endl;
    gagnerEnergie(35);
}

void Berserker::coupDechaine() {
    int damage = static_cast<int>(0.5 * pointsDeVie);
    pointsDeVie -= static_cast<int>(0.15 * pointsDeVie);  // Consomme 15% des PV
    std::cout << "Coup déchaîné : Inflige " << damage << " dégâts et consomme 15% des PV." << std::endl;
    gagnerEnergie(50);
}

void Berserker::movementAlpha() {
    if (energie >= 100) {
        int damage = static_cast<int>(0.75 * pointsDeVie);
        pointsDeVie += static_cast<int>(0.5 * pointsDeVie);  // Régénère 50% des PV
        std::cout << "Movement Alpha : Inflige " << damage << " dégâts et régénère 50% des PV." << std::endl;
        perdreEnergie(100);
    } else {
        std::cout << "Pas assez d'énergie pour Movement Alpha !" << std::endl;
    }
}
