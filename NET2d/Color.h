//
//  Color.hpp
//  NET2d
//
//  Created by Argha Chakraborty on 20/01/19.
//  Copyright © 2019 Argha Chakraborty. All rights reserved.
//

#ifndef Color_h
#define Color_h

#include <stdio.h>
class Color {
    double red, green, blue, special;
public:
    Color();
    Color(double, double, double, double);
    double getColorRed() { return red;}
    double getColorGreen() { return green;}
    double getColorBlue() { return blue;}
    double getColorSpecial() { return special;}
    void setColorRed(double r) { red = r;}
    void setColorGreen(double g) { green = g;}
    void setColorBlue(double b) { blue = b;}
    void setColorSpecial(double s) { special = s;}
    
    
};



#endif /* Color_hpp */
