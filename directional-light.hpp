//
//  directional-light.hpp
//  Raytracer
//
//  Created by Thibault Richel on 11/02/2022.
//

#ifndef directional_light_hpp
#define directional_light_hpp

#include <stdio.h>

#include "light.hpp"

class DirectionalLight: public Light{
    private:
        Vector3d lightDirection;
    public:
        DirectionalLight(Vector3d lightDirection_p, Color lightColor_p=Color(1, 1, 1));
        ~DirectionalLight(){}
        Vector3d getDirection();
        Color getColor();
};

#endif /* directional_light_hpp */
