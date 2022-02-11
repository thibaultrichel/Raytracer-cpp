//
//  scene.cpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#include "scene.hpp"
#include "Bmpfile.hpp"

Scene::Scene() {
    
}

void Scene::Render(std::string filename, unsigned int imgWidth, unsigned int imgHeight) {
    BMPFile file;
    unsigned int index = 0;
    unsigned char *buffer = new unsigned char[imgWidth*imgHeight*3];
    
    for (int y = 0; y < imgHeight; y++) {
        for (int x = 0; x < imgWidth; x++) {
            Color color = Scene::Raytrace(ray);    // ?
            buffer[index++] = color.getB();
            buffer[index++] = color.getG();
            buffer[index++] = color.getR();
        }
    }
    
    file.SaveBmp(filename, buffer, imgWidth, imgHeight);
}

void Scene::addObject(Object3D* obj) {
    objectList.push_back(obj);
}

Object3D* Scene::findNearestObject(const Ray &ray, double &distance) {
    Object3D *nearest = NULL;
    for (Object3D *obj : objectList) {
        double objDistance = obj->getIntersectionDistance(ray);
        if (objDistance >= 0) {
            if (objDistance < nearest->getIntersectionDistance(ray)) {
                nearest = obj;
            }
        }
    }
    return nearest;
}

Color Scene::Raytrace(const Ray &ray) {
    double dist = 1.;
    Object3D *nearestObject = Scene::findNearestObject(ray, dist);
    Color color = nearestObject->getColor();
    return color;
}
