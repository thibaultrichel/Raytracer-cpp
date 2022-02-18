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
    
    Sphere *sphere1 = new Sphere(Point3d(0, 0, 0), 0.2, 1, 10, 1);
    Sphere *sphere2 = new Sphere(Point3d(0, 0, 1), 0.1, 1, 10, 1);
    sphere1->setColor(Color(0, 1, 0));
    sphere2->setColor(Color(1, 0, 0));
    
    scene.addObject(sphere1);
    scene.addObject(sphere2);
    
    Vector3d lightDirection(0, 0, -1);
    DirectionalLight light(lightDirection, Color(1, 1, 1));
    scene.addLight(&light);
    
    string filename = "/Users/thibaultrichel/Desktop/test.bmp";
    unsigned int width = 800;
    unsigned int height = 800;
    
    scene.Render(filename, width, height);
    
    return 0;
}
