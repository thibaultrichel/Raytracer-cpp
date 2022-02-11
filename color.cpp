//
//  color.cpp
//  Raytracer
//
//  Created by Thibault Richel on 04/02/2022.
//

#include "color.hpp"

Color::Color(float r, float g, float b) {
    R = r;
    G = g;
    B = b;
}

float Color::getR() {
    return R;
}

float Color::getG() {
    return G;
}

float Color::getB() {
    return B;
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
