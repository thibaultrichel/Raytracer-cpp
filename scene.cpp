//
//  scene.cpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#include "scene.hpp"
#include "Bmpfile.hpp"
#include <iostream>
#include <cmath>


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
                                 -(double)(y - (int)(imgHeight / 2)) / (double)imgHeight, 0);
            Vector3d rayDir;
            Color pixelColor(0, 0, 0);
            
            rayDir = (bufferPoint - cameraPosition).Unit();
            Ray ray(cameraPosition, rayDir);
            
            Color color = Scene::Raytrace(ray);
            
            buffer[index++] = color.getB() * 255;
            buffer[index++] = color.getG() * 255;
            buffer[index++] = color.getR() * 255;
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
    double distanceToIntersection;
    Object3D *nearestObject = findNearestObject(ray, distanceToIntersection);
    if (!nearestObject) {
        return Color();
    }
    
    Point3d intersection = ray.getOrigin() + ray.getDir() * distanceToIntersection;
    Vector3d normalAtIntersection = nearestObject->getNormalAt(intersection);
    
    return computeLocalIllumination(nearestObject, intersection, normalAtIntersection, ray);
}

Color Scene::computeLocalIllumination(Object3D *object, const Vector3d &intersection, const Vector3d &normalAtIntersection, const Ray &ray)
{
    Color color;
    float specularLightFactor = 0.0;
    Color specularLight(0, 0, 0);
    for (unsigned int i = 0; i < lights.size(); i++) {
        Vector3d toObserver = ray.getDir() * (-1);
        Vector3d vToLight = lights[i]->getVectorToLightAtPoint(intersection);
        double scal = normalAtIntersection.Dot(vToLight);
        if (scal > 0) {
            Vector3d reflexionVector = (normalAtIntersection * (2 * normalAtIntersection.Dot(vToLight)) - vToLight).Unit();
            specularLightFactor = std::pow(std::max(reflexionVector.Dot(toObserver), (double) 0), object->getNs()) * object->getKs();
            color += object->getColor() * scal;
            specularLight += lights[i]->getColor() * specularLightFactor;
        }
    }
    
    color += specularLight;
    return color;
}

void Scene::addLight(Light* light) {
    lights.push_back(light);
}
