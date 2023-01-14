//
// Created by Hemmy on 14/01/2023.
//

#ifndef RAYTRACING_WEEKEND_MATH_H
#define RAYTRACING_WEEKEND_MATH_H

#include <cmath>
#include <iostream>
#include <array>




// Template vector class that defaults to float and using 3 values and
template<class Type = float , int SIZE = 3>
struct Vector
{
	
	constexpr Vector(){
		// we default to a size of 3, so we manually set the values here.
		std::fill(e.begin(),e.end(),0);
	}

	// Make a vector with any number of components.
	template<class ... Components>
	explicit Vector(Components... elems)
	{
		e = std::array<Type, sizeof...(elems)>(elems...);
	}
	
	std::array<Type,SIZE> e;
	
	Type x() const {return e.at(0);};
	Type y() const {return e.at(1);};
	Type z() const {return e.at(2);};

	// enable only if size is >= 4
	Type w() const requires (SIZE >= 4) {return e.at(3);};



};
#endif //RAYTRACING_WEEKEND_MATH_H
