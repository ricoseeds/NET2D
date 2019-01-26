//
//  Sphere.hpp
//  NET2d
//
//  Created by Argha Chakraborty on 21/01/19.
//  Copyright © 2019 Argha Chakraborty. All rights reserved.
//

#ifndef Plane_h
#define Plane_h

//#include <math.h>
//#include "MySceneObject.h"
#include "Vect.h"
#include "Color.h"
#include "MySceneObject.h"

class Plane : public MySceneObject {
private:
	Vect normal;
	double distanceFromOrigin;
    Color color;
public:
	Plane();
	Plane(Vect normal, double distance, Color color);

	Vect getNormal() const;
	double getDistanceFromOrigin() const;

	Vect getNormalAt(Vect position);
	double findRayIntersection(Ray ray);
	Color getColor() const;
};


Plane::Plane(){
	normal = Vect(1.0, 0.0, 0.0);
	distanceFromOrigin = 0.0;
	color = Color(0.5, 0.5, 0.5, 0.0);
}

Plane::Plane(Vect normal, double distance, Color color){
	normal = normal;
	distanceFromOrigin = distance;
    color = Color(0.5, 0.5, 0.5, 0.0);
}

Vect Plane::getNormal() const {
	return normal;
}

double Plane::getDistanceFromOrigin() const {
	return this->distanceFromOrigin;
}

Vect Plane::getNormalAt(Vect position){
	return normal;
}

//returns the distance from point of intersection to the ray origin
double Plane::findRayIntersection(Ray ray){
	Vect rayDirection = ray.getRayDirection();
	double a = rayDirection.dotProduct(normal);
	if (a == 0){
		//Ray is parallel to the plane.
		return -1.0;
	}
	else {
		double b = normal.dotProduct(ray.getRayOrigin().vectAdd(normal.vectMult(distanceFromOrigin).negative()));
		return (-1*b)/a; //Distance from ray origin to point intersection.
	}
}

Color Plane::getColor() const {
	return color;
}

#endif /* Sphere_hpp */
