//
//  Ray.h
//  NET2d
//
//  Created by Argha Chakraborty on 19/01/19.
//  Copyright © 2019 Argha Chakraborty. All rights reserved.
//

#ifndef Ray_h
#define Ray_h

#include "Vect.h"

class Ray {
    Vect origin, direction;
public:
    Ray();
    Ray(Vect, Vect);
    Vect getRayOrigin(){
        return origin;
    }
    
    Vect getRayDirection(){
        return direction;
    }
    
};

Ray::Ray(){
    origin = Vect(0, 0, 0);
    direction = Vect(1, 0, 0);
    
}

Ray::Ray(Vect o, Vect d){
    origin = o;
    direction = d;

}


#endif /* Ray_h */
