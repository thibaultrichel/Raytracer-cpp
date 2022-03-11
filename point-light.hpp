//
//  point-light.hpp
//  Raytracer
//
//  Created by Thibault Richel on 11/03/2022.
//

#ifndef point_light_hpp
#define point_light_hpp

#include "light.hpp"
#include <stdio.h>

class PointLight: public Light{
    private:
        Vector3d position;
    public:
        PointLight(Vector3d position_p, Color lightColor_p=Color(1, 1, 1));
        ~PointLight(){};
        Vector3d getPosition();
        Color getColor();
        Vector3d getVectorToLightAtPoint(Vector3d point);
};

#endif /* point_light_hpp */
