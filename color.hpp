//
//  color.hpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#ifndef color_hpp
#define color_hpp

#include <stdio.h>

class Color {
private:
    float R;
    float G;
    float B;
public:
    Color(float r=0, float g=0, float b=0);
    float getR();
    float getG();
    float getB();
    
    Color operator * (const float k);
    Color operator * (const Color c);
    Color operator + (const Color c);
    Color operator = (const Color c);
    Color operator *= (const Color c);
    Color operator += (const Color c);
    Color operator *= (const float k);
};

#endif /* color_hpp */
