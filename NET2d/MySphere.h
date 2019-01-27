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
    double findRayIntersection(Ray ray);
    Vect getNormalAt(Vect position);
    
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

double MySphere::findRayIntersection(Ray ray){
    Vect ray_origin = ray.getRayOrigin();
    double ray_origin_x = ray_origin.getVectX();
    double ray_origin_y = ray_origin.getVectY();
    double ray_origin_z = ray_origin.getVectZ();
    Vect ray_dir = ray.getRayDirection();
    double ray_dir_x = ray_dir.getVectX();
    double ray_dir_y = ray_dir.getVectY();
    double ray_dir_z = ray_dir.getVectZ();

    Vect sphere_center = center;
    double sphere_center_x = sphere_center.getVectX();
    double sphere_center_y = sphere_center.getVectY();
    double sphere_center_z = sphere_center.getVectZ();

    double a = 1;
    double b = (2 * (ray_origin_x - sphere_center_x) * ray_dir_x) + (2 * (ray_origin_y - sphere_center_y) * ray_dir_y) + (2 * (ray_origin_z - sphere_center_z) * ray_dir_z);
    double c = pow(ray_origin_x - sphere_center_x, 2) + pow(ray_origin_y - sphere_center_y, 2) + pow(ray_origin_z - sphere_center_z, 2) - (radius*radius);
    double discriminant = (b * b) - 4 * a * c;
    if (discriminant > 0) {
        //ray intersects sphere
        //root 1
        double root1 = ((-b - sqrt(discriminant))/ 2) - 0.00001;
        if (root1 > 0) {
            return root1;
        } else {
            double root1 = ((-b + sqrt(discriminant))/ 2) - 0.00001;
        }
        

    } else {
        //The ray missed the sphere
        return -1;
    }
    


}

Vect MySphere::getNormalAt(Vect point){
    Vect normal_vect = point.vectAdd(center.negative()).normalize();
    return normal_vect;    
}

#endif /* Sphere_hpp */
