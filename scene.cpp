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
    Vector3d cameraPosition(0, 0, 10);
        
    for (int y = 0; y < imgHeight; y++) {
        for (int x = 0; x < imgWidth; x++) {
            Vector3d bufferPoint((double)(x - (int)(imgWidth / 2)) / (double)imgWidth,
                                 - (double)(y - (int)(imgHeight / 2)) / (double)imgHeight, 0);
            Vector3d rayDir;
            Color pixelColor(0, 0, 0);
            
            rayDir = (bufferPoint - cameraPosition).Unit();
            Ray ray(cameraPosition, rayDir);
            
            Color color = Scene::Raytrace(ray);
            buffer[index++] = (unsigned char) color.getB() * 255;
            buffer[index++] = (unsigned char) color.getG() * 255;
            buffer[index++] = (unsigned char) color.getR() * 255;
        }
    }
    
    file.SaveBmp(filename, buffer, imgWidth, imgHeight);
}

void Scene::addObject(Object3D* obj) {
    objectList.push_back(obj);
}

Object3D* Scene::findNearestObject(const Ray &ray, double &distance) {
    Object3D *nearest = NULL;
    double nearestDistance = 100000.0;
    for (Object3D *obj : objectList) {
        double objDistance = obj->getIntersectionDistance(ray);
        if (objDistance >= 0) {
            if (objDistance < nearestDistance) {
                nearest = obj;
                nearestDistance = objDistance;
            }
        }
    }
    return nearest;
}

Color Scene::Raytrace(const Ray &ray) {
    double dist = 1.;
    Object3D *nearestObject = Scene::findNearestObject(ray, dist);
    if (nearestObject == NULL) {
        return Color(0, 0, 0);
    }
    Color color = nearestObject->getColor();
    return color;
}
