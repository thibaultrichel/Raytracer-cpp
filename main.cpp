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
    
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 6; i++) {
            double x = -0.5 + i * 0.2;
            double y = 0.5 + j * -0.2;
            Sphere *sphere = new Sphere(Point3d(x, y, 0), 0.1, 0.7, 50.0);
            double random = ((double)rand()/(double)RAND_MAX);
            Color color(random, random, random);
            sphere->setColor(color);
            scene.addObject(sphere);
        }
    }
    
    Vector3d lightPos(2, 2, 4);
    PointLight light(lightPos, Color(1, 1, 1));
    scene.addLight(&light);
    
    string filename = "/Users/thibaultrichel/Desktop/render_Thibault_RICHEL.bmp";
    unsigned int width = 1500;
    unsigned int height = 1500;
    
    scene.Render(filename, width, height);
    
    return 0;
}
