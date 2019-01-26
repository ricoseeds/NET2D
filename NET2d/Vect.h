//
//  Vect.h
//  NET2d
//
//  Created by Argha Chakraborty on 19/01/19.
//  Copyright © 2019 Argha Chakraborty. All rights reserved.
//

#ifndef VECT_H
#define VECT_H

#include "math.h"

class Vect {
    double x, y, z;
public:
    Vect();
    Vect(double, double, double);
    double getVectX() { return x;}
    double getVectY() { return y;}
    double getVectZ() { return z;}
    double magnitude();
    Vect normalize();
    Vect negative();
    double dotProduct(Vect);
    Vect crossProduct(Vect);
    Vect vectAdd(Vect);
    Vect vectMult(double);
};

#endif /* Vect_h */
