//
//  object.cpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#include "object.hpp"

Color Object::getColor() {
    return color;
}

void Object::setColor(Color color_p) {
    color = color_p;
}
