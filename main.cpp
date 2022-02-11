//
//  main.cpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#include <iostream>
#include "scene.hpp"
#include "sphere.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Scene scene;
    
    Sphere *sphere = new Sphere(Point3d(0, 0, 0), 1.);
    
    scene.addObject(sphere);
    
    string filename = "/Users/thibaultrichel/Desktop/test.bmp";
    unsigned int width = 400;
    unsigned int height = 400;
    
    scene.Render(filename, width, height);
    
    return 0;
}
