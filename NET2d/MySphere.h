//
//  Sphere.hpp
//  NET2d
//
//  Created by Argha Chakraborty on 21/01/19.
//  Copyright © 2019 Argha Chakraborty. All rights reserved.
//

#ifndef My_Sphere_h
#define My_Sphere_h

#include <math.h>
#include "Vect.h"
#include "Color.h"

class Sphere {
    Vect center;
    double radius;
    Color color;
public:
    Sphere();
    Sphere(Vect, double, Color);
    Vect getSphereCenter(){
        return center;
    }
    
    Color getSphereColor(){
        return color;
    }
    
    double getSphereRadius(){
        return radius;
    }
    
};

Sphere::Sphere(){
    center = Vect(0, 0, 0);
    radius = 1.0;
    color = Color(0.5, 0.5, 0.5, 0);
    
}

Sphere::Sphere(Vect p, double r, Color c){
    center = p;
    radius = r;
    color = c;
}

#endif /* Sphere_hpp */
