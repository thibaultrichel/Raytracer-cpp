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
    
    Sphere *sphere1 = new Sphere(Point3d(-0.2, -0.3, 0), 0.15, 1, 10, 0);
    sphere1->setColor(Color(0.8, 0, 0));
    scene.addObject(sphere1);

    Sphere *sphere2 = new Sphere(Point3d(-0.2, 0.25, -1), 0.25, 1, 10, 1);
    sphere2->setColor(Color(0, 0, 0.8));
    scene.addObject(sphere2);
    
    Sphere *sphere3 = new Sphere(Point3d(0.2, -0.1, 0), 0.25, 1, 10, 1);
    sphere3->setColor(Color(0, 0.8, 0));
    scene.addObject(sphere3);
    
    Sphere *sphere4 = new Sphere(Point3d(0, 0, -5), 4, 1, 10, 0);
    sphere4->setColor(Color(0.85, 0.5, 0.82));
    scene.addObject(sphere4);
    
    Vector3d lightDir1(-1, -1, 0);
    DirectionalLight light1(lightDir1, Color(1, 1, 1));
    scene.addLight(&light1);
    
    Vector3d lightDir2(0, 0, -1);
    DirectionalLight light2(lightDir2, Color(1, 1, 1));
    scene.addLight(&light2);
    
    string filename = "/Users/thibaultrichel/Desktop/test.bmp";
    unsigned int width = 800;
    unsigned int height = 800;
    
    scene.Render(filename, width, height);
    
    return 0;
}
