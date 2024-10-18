#ifndef BERSERKER_H
#define BERSERKER_H

#include "Personnage.h"

class Berserker : public Personnage {
public:
    Berserker(int pv, int atk, int def, double spd);
    
    void frappePunitive();
    void coupDechaine();
    void movementAlpha();
};

#endif // BERSERKER_H
