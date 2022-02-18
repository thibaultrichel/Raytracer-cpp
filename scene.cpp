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
    double distance;
    Object3D *nearestObject = Scene::findNearestObject(ray, distance);
    Color color;
    Color finalColor(0, 0, 0);

    if (nearestObject == NULL) {
        return Color(0, 0, 0);
    }

    color = nearestObject->getColor();
    Vector3d spherePoint = ray.getOrigin() + (ray.getDir() * distance);
    Vector3d normalVector = nearestObject->getNormalAt(spherePoint);
    Vector3d toObserver = ray.getDir() * (-1);

    double diffuseLightFactor = 0.5;
    double specularLightFactor = 0.5;
    double zero = 0.0;
    Color diffuseLight(0, 0, 0);
    Color specularLight(0, 0, 0);

    for (int i = 0; i < lights.size(); i++) {
        Vector3d lightDir = lights[i]->getDirection();
        Vector3d toLight = (lightDir * (-1));

        // Lambert model : diffused light
        diffuseLightFactor = std::max(normalVector.Dot(toLight), zero);
        diffuseLight = diffuseLight + lights[i]->getColor() * diffuseLightFactor;

        // Phong model : specular light
        Vector3d reflexionVector = (normalVector * (2 * normalVector.Dot(toLight)) - toLight).Unit();
        specularLightFactor = std::pow(std::max(reflexionVector.Dot(toObserver), zero), nearestObject->getNs()) * nearestObject->getKs();
        specularLight = specularLight + lights[i]->getColor() * specularLightFactor;
    }

    finalColor += color * diffuseLight;
    finalColor += specularLight;

    Vector3d reflectedRayDir = (normalVector * (2 * normalVector.Dot(toObserver)) - toObserver).Unit();
    Ray reflectedRay(spherePoint, reflectedRayDir);

//    if (finalColor.getR() != 0 and finalColor.getG() != 0 and finalColor.getB() != 0) {
//        std::cout << finalColor.getR() << ";" << finalColor.getG() << ";" << finalColor.getB() << std::endl;
//    }
    
    return finalColor;
}

void Scene::addLight(Light* light) {
    lights.push_back(light);
}
