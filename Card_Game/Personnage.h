#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>

class Personnage {
public:
    int pointsDeVie;
    int attaque;
    int defense;
    double vitesse;
    int energie;

    Personnage(int pv, int atk, int def, double spd);
    virtual ~Personnage() {}

    virtual void frappePreventive();
    virtual void blast();
    virtual void attaqueDelta();  // Attaque spéciale

    void gagnerEnergie(int montant);
    void perdreEnergie(int montant);
};

#endif // PERSONNAGE_H
