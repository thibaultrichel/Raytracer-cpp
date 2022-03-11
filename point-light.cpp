//
//  point-light.cpp
//  Raytracer
//
//  Created by Thibault Richel on 11/03/2022.
//

#include "point-light.hpp"

PointLight::PointLight(Vector3d position_p, Color color_p): Light(color_p){
    position = position_p.Unit();
}

Vector3d PointLight::getPosition(){
    return position;
}

Color PointLight::getColor(){
    return lightColor;
}

Vector3d PointLight::getVectorToLightAtPoint(Vector3d point) {
    return (point - position).Unit();
}
