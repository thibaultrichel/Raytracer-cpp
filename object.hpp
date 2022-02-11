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

class Object {
public:
    virtual double getIntersectionDistance(const Ray &ray) = 0;
    Color getColor();
    void setColor(Color color);
private:
    Color color;
};

#endif /* object_hpp */
