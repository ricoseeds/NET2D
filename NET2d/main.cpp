#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Vect.h"
#include "Camera.h"
#include "Color.h"
#include "MyLight.h"
#include "MySceneObject.h"
#include "MySphere.h"

using namespace std;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define DPI 72

struct RGBType{
    double r;
    double g;
    double b;
};

void save_image(const char *filename, int w, int h, int dpi, RGBType *data){
    FILE *f;
    int k = w * h;
    int s = 4 * k;
    int filesize = 54 + s;
    double factor = 39.375;
    int m = static_cast<int>(factor);
    int ppm = dpi * m;
    unsigned char bmpfileheader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    unsigned char bmpinfoheader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 1, 0, 24, 0};
    bmpfileheader[2] = (unsigned char) (filesize);
    bmpfileheader[3] = (unsigned char) (filesize >> 8);
    bmpfileheader[4] = (unsigned char) (filesize >> 16);
    bmpfileheader[5] = (unsigned char) (filesize >> 24);
    
    bmpinfoheader[4] = (unsigned char)(w);
    bmpinfoheader[5] = (unsigned char)(w >> 8);
    bmpinfoheader[6] = (unsigned char)(w >> 16);
    bmpinfoheader[7] = (unsigned char)(w >> 24);
    
    bmpinfoheader[8] = (unsigned char)(h);
    bmpinfoheader[9] = (unsigned char)(h >> 8);
    bmpinfoheader[10] = (unsigned char)(h >> 16);
    bmpinfoheader[11] = (unsigned char)(h >> 24);
    
    bmpinfoheader[21] = (unsigned char)(s);
    bmpinfoheader[22] = (unsigned char)(s >> 8);
    bmpinfoheader[23] = (unsigned char)(s >> 16);
    bmpinfoheader[24] = (unsigned char)(s >> 24);
    
    bmpinfoheader[25] = (unsigned char)(ppm);
    bmpinfoheader[26] = (unsigned char)(ppm >> 8);
    bmpinfoheader[27] = (unsigned char)(ppm >> 16);
    bmpinfoheader[28] = (unsigned char)(ppm >> 24);
    
    bmpinfoheader[29] = (unsigned char)(ppm);
    bmpinfoheader[30] = (unsigned char)(ppm >> 8);
    bmpinfoheader[31] = (unsigned char)(ppm >> 16);
    bmpinfoheader[32] = (unsigned char)(ppm >> 24);
    
    f = fopen(filename, "wb");
    fwrite(bmpfileheader, 1, 14, f);
    fwrite(bmpinfoheader, 1, 40, f);
    
    for(int i = 0; i < k; i++){
//        RGBType rgb = data[i];
        double red = (data[i].r) * 255;
        double green = (data[i].g) * 255;
        double blue = (data[i].b) * 255;
        unsigned char color[3] = {static_cast<unsigned char>((int)floor(blue)), static_cast<unsigned char>((int)floor(green)), static_cast<unsigned char>((int)floor(red))};
        fwrite(color, 1, 3, f);
    }
    fclose(f);
    
}

int main(int argc, char *argv[]){
    //cout << "Hello";
    int n = SCREEN_WIDTH * SCREEN_HEIGHT;
    RGBType *pixels = new RGBType[n];
    Vect origin(0, 0, 0);
    Vect X(1, 0, 0);
    Vect Y(0, 1, 0);
    Vect Z(0, 0, 1);
    
    Vect campos(3, 1.5, -4);
    // for the camera
    Vect lookat(0, 0, 0);
    Vect diff_btw(campos.getVectX() - lookat.getVectX(), campos.getVectY() - lookat.getVectY(), campos.getVectZ() - lookat.getVectZ());
    Vect camDir = diff_btw.negative().normalize();
    Vect camright = Y.crossProduct(camDir).normalize();
    Vect camdown = camright.crossProduct(camDir);
    Camera scene_cam(campos, camDir, camright, camdown);
    
    Color white_light(1.0, 1.0, 1.0, 0);
    Color green_color(0.5, 1.0, 0.5, 0.3);
    Color gray(0.5, 0.5, 0.5, 0);
    Color black(0.0, 0.0, 0.0, 0);
    
    Vect light_pos(-7, 10, -10);
    MyLight scene_light(light_pos, white_light);
    
    // Scene objects
//    MySphere scene_sphere(origin, 1, green_color);
    
    int index;
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            index = (y * SCREEN_WIDTH) + x;
            pixels[index].r = (double) 23 / 255.0;
            pixels[index].g = (double) 222 / 255.0;
            pixels[index].b = (double) 10 / 255.0;
        }
    }
    save_image("/Users/arghachakraborty/Desktop/pinku.bmp", SCREEN_WIDTH, SCREEN_HEIGHT, DPI, pixels);
    
}

