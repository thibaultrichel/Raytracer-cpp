//
//  object.cpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#include "object.hpp"

Object3D::Object3D(float ks_p, float nShiny_p){
    ks = ks_p;
    nShiny = nShiny_p;
}

Object3D::~Object3D() {
    
}

Color Object3D::getColor() {
    return color;
}

void Object3D::setColor(Color color_p) {
    color = color_p;
}

float Object3D::getKs() {
    return ks;
}

float Object3D::getNs() {
    return nShiny;
}
float Object3D::getKr() {
    return kr;
}
