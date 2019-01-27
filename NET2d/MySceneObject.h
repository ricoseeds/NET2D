//
//  Object.h
//  NET2d
//
//  Created by Argha Chakraborty on 23/01/19.
//  Copyright © 2019 Argha Chakraborty. All rights reserved.
//

#ifndef My_Scene_Object_h
#define My_Scene_Object_h
//
//#include "Ray.h"
//#include "Color.h"

//#include "Ray.h"

#include "Ray.h"
#include "Color.h"

class MySceneObject {
protected:
    Color color;
public:
    MySceneObject(){
        
    }
    Color getObjectColor(){
        return Color(0.0, 0.0, 0.0, 0);
    }
    void setObjectColor(Color color);
    virtual double findRayIntersection(Ray ray){
        return 0.0;
    }
    virtual Vect getNormalAt(Vect position){
         return Vect(0, 0, 0);
     }
};


#endif /* Object_h */