//
//  Camera.h
//  NET2d
//
//  Created by Argha Chakraborty on 19/01/19.
//  Copyright © 2019 Argha Chakraborty. All rights reserved.
//

#ifndef Camera_h
#define Camera_h

#include "Vect.h"

class Camera {
    // camright and camdown are used to define the general cood system for scene
    Vect campos, camdir, camright, camdown;
    
public:
    Camera();
    Camera(Vect, Vect, Vect, Vect);
    const Vect getCameraPosition(){
        return campos;
    }
    
    const Vect getCameraDirection(){
        return camdir;
    }
    
    const Vect getCameraRight(){
        return camright;
    }
    
    const Vect getCameraDown(){
        return camdown;
    }
};

Camera::Camera(){
    campos = Vect();
    camdir = Vect(0, 0, 1);
    camright = Vect();
    camdown = Vect();
}

Camera::Camera(Vect p, Vect d, Vect r, Vect dn){
    campos = p;
    camdir = d;
    camright = r;
    camdown = d;
}
#endif /* Camera_h */
