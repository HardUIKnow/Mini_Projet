#ifndef SNOWQUEEN_H
#define SNOWQUEEN_H

#include "Personnage.h"

class SnowQueen : public Personnage {
public:
    SnowQueen(int pv, int atk, int def, double spd);

    void javelotDeGlace();
    void ventGlaciale();
    void letItGo();
};

#endif // SNOWQUEEN_H
