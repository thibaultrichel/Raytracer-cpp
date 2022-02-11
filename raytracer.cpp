//
//  raytracer.cpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#include "raytracer.hpp"

Ray::Ray(Point3d origin_p, Vector3d dir_p) {
    origin = origin_p;
    dir = dir_p.Unit();
}

Point3d Ray::getOrigin() const {
    return origin;
}

Vector3d Ray::getDir() const {
    return dir;
}
