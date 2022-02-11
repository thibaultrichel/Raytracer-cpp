//
//  color.cpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#include "color.hpp"

Color::Color(int r, int g, int b) {
    R = r;
    G = g;
    B = b;
}

Color Color::operator * (const float k){
    return Color(R * k, G * k, B * k);
}


Color Color::operator * (const Color c){
    return Color(R * c.R, G * c.G, B * c.B);
}

Color Color::operator + (const Color c){
    return Color(R + c.R, G + c.G, B + c.B);
}

Color Color::operator = (const Color c){
    R = c.R;
    G = c.G;
    B = c.B;

    return *this;
}

Color Color::operator *= (const Color c){
    R *= c.R;
    G *= c.G;
    B *= c.B;

    return *this;
}

Color Color::operator *= (const float k){
    R *= k;
    G *= k;
    B *= k;

    return *this;
}

Color Color::operator += (const Color c){
    R += c.R;
    G += c.G;
    B += c.B;

    return *this;
}
