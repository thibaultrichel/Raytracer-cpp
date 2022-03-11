//
//  object.hpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#ifndef object_hpp
#define object_hpp

#include <stdio.h>
#include "raytracer.hpp"
#include "color.hpp"

class Object3D {
private:
    Color color;
    float ks;
    float nShiny;
    float kr;
public:
    Object3D(float ks_p, float nShiny_p);
    virtual ~Object3D();
    virtual double getIntersectionDistance(const Ray &ray) = 0;
    virtual Vector3d getNormalAt(Vector3d point) = 0;
    Color getColor();
    void setColor(Color color);
    float getKs();
    float getNs();
    float getKr();
};

#endif /* object_hpp */
