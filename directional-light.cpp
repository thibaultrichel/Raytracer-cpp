//
//  directional-light.cpp
//  Raytracer
//
//  Created by Thibault Richel on 11/02/2022.
//

#include "directional-light.hpp"

DirectionalLight::DirectionalLight(Vector3d lightDirection_p, Color color_p): Light(color_p){
    lightDirection = lightDirection_p.Unit();
}


Vector3d DirectionalLight::getDirection(){
    return lightDirection;
}


Color DirectionalLight::getColor(){
    return lightColor;
}
