//
//  light.hpp
//  Raytracer
//
//  Created by Thibault Richel on 11/02/2022.
//

#ifndef light_hpp
#define light_hpp

#include <stdio.h>

#include "color.hpp"
#include "vector3d.hpp"

class Light{
    protected:
        Color lightColor;

    public:
        Light(Color lightColor_p);
        ~Light(){}
        virtual Color getColor() = 0;
        virtual Vector3d getPosition() = 0;
        virtual Vector3d getVectorToLightAtPoint(Vector3d point) = 0;
};

#endif /* light_hpp */
