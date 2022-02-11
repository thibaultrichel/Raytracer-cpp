//
//  raytracer.hpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#ifndef raytracer_hpp
#define raytracer_hpp

#include "vector3d.hpp"

class Ray {
private:
    Point3d origin;
    Vector3d dir;
public:
    Ray(Vector3d Point3d, Vector3d dir_p);
    ~Ray(){}
    Point3d getOrigin() const;
    Vector3d getDir() const;
};

#endif /* raytracer_hpp */
