//
//  Vect.cpp
//  NET2d
//
//  Created by Argha Chakraborty on 19/01/19.
//  Copyright © 2019 Argha Chakraborty. All rights reserved.
//

#include "Vect.h"
Vect::Vect(){
    x = 0;
    y = 0;
    z = 0;
}

Vect::Vect(double i, double j, double k){
    x = i;
    y = j;
    z = k;
}

double Vect::magnitude(){
    return sqrt((x * x)+ (y * y) + (z * z));
}

Vect Vect::normalize(){
    double m = magnitude();
    return Vect(x/m, y/m, z/m);
}

Vect Vect::negative(){
    return Vect(-x, -y, -z);
}

double Vect::dotProduct(Vect v){
    return x * v.getVectX() + y * v.getVectY() + z * v.getVectZ();
}

Vect Vect::crossProduct(Vect v){
    double dirI = (y * v.z) - (z * v.y) ;
    double dirJ = (v.x * z) - (x * v.z);
    double dirK = (x * v.y) - (v.x * y);
    return Vect(dirI, dirJ, dirK);
}

Vect Vect::vectAdd(Vect v){
    return Vect(x + v.getVectX(), y + v.getVectY(), z + v.getVectZ());
}

Vect Vect::vectMult(double k){
    return Vect(x * k, y * k, z * k);
}


