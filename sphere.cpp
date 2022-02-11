//
//  sphere.cpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#include "sphere.hpp"

Sphere::Sphere(Point3d center_p, float R_p) {
    center = center_p;
    R = R_p;
}

double Sphere::getIntersectionDistance(const Ray &ray) {
    // Points
    Vector3d src_point = ray.getOrigin();

    //Vectors
    Vector3d dir = ray.getDir();

    //t-Computing
    Vector3d sphere_to_point = src_point - center;

    float a = 1;
    float b = 2 * (dir.Dot(sphere_to_point));
    float c = sphere_to_point.Dot(sphere_to_point) - pow(R, 2);

    float delta = pow(b, 2) - (4 * a * c);

    float t1, t2, t;
    t = -1;
    if(delta > 0){
        t1 = (- b + sqrt(delta)) / (2 * a);
        t2 = (- b - sqrt(delta)) / (2 * a);
        if(t1 > 0 && t2 > 0){
            t = std::min(t1, t2);
        }
        else if(t1 < 0  && t2 > 0){
            t = t2;
        }
        else if(t2 < 0  && t1 > 0){
            t = t1;
        }
        return t;
    }
    else if(delta == 0){
        float t_p = (-b / (2 * a));
        if(t_p > 0){
            t = t_p;
            return  t;
        }
    }
    return t;
}
