//
//  sphere.hpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#ifndef sphere_hpp
#define sphere_hpp

#include <stdio.h>
#include "object.hpp"

class Sphere: public Object3D {
private:
    Point3d center;
    float R;
public:
    virtual double getIntersectionDistance(const Ray &ray);
    Sphere(Point3d center_p, float R_p, float ks_p=0.0, float nShiny_p=0.0);
    Vector3d getNormalAt(Vector3d point);
};

#endif /* sphere_hpp */
