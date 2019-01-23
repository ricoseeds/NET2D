//
//  Light.hpp
//  NET2d
//
//  Created by Argha Chakraborty on 20/01/19.
//  Copyright © 2019 Argha Chakraborty. All rights reserved.
//

#ifndef My_Light_h
#define My_Light_h

#include "Vect.h"
#include "Color.h"

class MyLight {
    Vect position;
    Color color;
public:
    MyLight();
    MyLight(Vect, Color);
    virtual Vect getLightPosition(){
        return position;
    }
    
    virtual Color getLightColor(){
        return color;
    }
    
};

MyLight::MyLight(){
    position = Vect(0, 0, 0);
    color = Color(1, 1, 1, 0);
    
}

MyLight::MyLight(Vect p, Color c){
    position = p;
    color = c;
}


#endif /* Light_hpp */
