//
//  scene.hpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#ifndef scene_hpp
#define scene_hpp

#include <string>
#include <vector>
#include <cstdlib>
#include "object.hpp"

class Scene
{
private:
    std::vector<Object3D*> objectList;
public:
    Scene();
    void Render(std::string filename, unsigned int imgWidth, unsigned int imgHeight);
    void addObject(Object3D* obj);
    Color Raytrace(const Ray &ray);
    Object3D* findNearestObject(const Ray &ray, double &distance);
};

#endif /* scene_hpp */
