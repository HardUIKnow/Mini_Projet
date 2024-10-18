#include "SnowQueen.h"
#include <iostream>

SnowQueen::SnowQueen(int pv, int atk, int def, double spd)
    : Personnage(pv, atk, def, spd) {}

void SnowQueen::javelotDeGlace() {
    int damage = static_cast<int>(12.5 * this->attaque);
    std::cout << "Javelot de glace a Infligé "<< damage << "pts de degats." << std::endl;
    gagnerEnergie(30);
}

void SnowQueen::ventGlaciale() {
    int damage = static_cast<int>(15 * this->attaque);
    std::cout << "Vent glaciale a infligé "<< damage << "pts de degats." << std::endl;
    gagnerEnergie(40);
}

void SnowQueen::letItGo() {
    if (energie >= 100) {
        int damage = static_cast<int>(17.5 * this->attaque);
        std::cout << "Let It Go a infligé "<< damage << "pts de degats" << std::endl;
        perdreEnergie(100);
    } else {
        std::cout << "Pas assez d'énergie pour Let It Go !" << std::endl;
    }
}
