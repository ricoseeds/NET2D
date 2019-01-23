//
//  Color.cpp
//  NET2d
//
//  Created by Argha Chakraborty on 20/01/19.
//  Copyright © 2019 Argha Chakraborty. All rights reserved.
//

#include "Color.h"

Color::Color(){
    red = 0.5;
    green = 0.5;
    blue = 0.5;
    special = 0;
}

Color::Color(double r, double g, double b, double s){
    red = r;
    green = g;
    blue = b;
    special = s;
}



