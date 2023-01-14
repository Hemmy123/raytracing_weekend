//
// Created by Hemmy on 14/01/2023.
//

#ifndef RAYTRACING_WEEKEND_MATH_H
#define RAYTRACING_WEEKEND_MATH_H

#include <cmath>
#include <iostream>
#include <array>
// Template vector clas that defaults to 3
template<class Type = float , int SIZE = 3>
struct Vector
{
    std::array<Type,SIZE> elems[SIZE]{};



};


#endif //RAYTRACING_WEEKEND_MATH_H
