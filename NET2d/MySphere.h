//
//  Sphere.hpp
//  NET2d
//
//  Created by Argha Chakraborty on 21/01/19.
//  Copyright © 2019 Argha Chakraborty. All rights reserved.
//

#ifndef My_Sphere_h
#define My_Sphere_h

//#include <math.h>
//#include "MySceneObject.h"
#include "Vect.h"
#include "Color.h"
#include "MySceneObject.h"

class MySphere : public MySceneObject{
    Vect center;
    double radius;
    Color color;
public:
    MySphere();
    MySphere(Vect, double, Color);
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

MySphere::MySphere(){
    center = Vect(0, 0, 0);
    radius = 1.0;
    color = Color(0.5, 0.5, 0.5, 0);
    
}

MySphere::MySphere(Vect p, double r, Color c){
    center = p;
    radius = r;
    color = c;
}

#endif /* Sphere_hpp */
