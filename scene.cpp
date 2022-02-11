//
//  scene.cpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#include "scene.hpp"
#include "Bmpfile.hpp"


void Scene::Render(std::string filename, unsigned int imgWidth, unsigned int imgHeight) {
    BMPFile file;
    unsigned int index = 0;
    unsigned char *buffer = new unsigned char[imgWidth*imgHeight*3];
    
    for (int y = 0; y < imgHeight; y++) {
        for (int x = 0; x < imgWidth; x++) {
            buffer[index++] = 255;
            buffer[index++] = 0;
            buffer[index++] = 0;
        }
    }
    
    file.SaveBmp(filename, buffer, imgWidth, imgHeight);
}

void Scene::addObject(Object* obj) {
    objectList.push_back(obj);
}
