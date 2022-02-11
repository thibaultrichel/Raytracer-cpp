//
//  object.cpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#include "object.hpp"

Object3D::Object3D() {
    
}

Object3D::~Object3D() {
    
}

Color Object3D::getColor() {
    return color;
}

void Object3D::setColor(Color color_p) {
    color = color_p;
}
