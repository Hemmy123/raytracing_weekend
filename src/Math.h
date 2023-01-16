//
// Created by Hemmy on 14/01/2023.
//

#ifndef RAYTRACING_WEEKEND_MATH_H
#define RAYTRACING_WEEKEND_MATH_H

#include <cmath>
#include <iostream>
#include <array>




// Template vector class that defaults to float and using 3 values and
template<class TYPE = float , int SIZE = 3>
struct Vector
{
	std::array<TYPE,SIZE> e;

	Vector(){
		std::fill(e.begin(),e.end(),0);
	}

	// A bit of a hack to get std::array with initialise with
	// an initializer list....
	// Code from: https://stackoverflow.com/questions/38932089/can-i-initialize-an-array-using-the-stdinitializer-list-instead-of-brace-enclo
	template<typename T, std::size_t N, std::size_t ...Ns>
	std::array<T, N> make_array_impl(
			std::initializer_list<T> t,
			std::index_sequence<Ns...>)
	{
		// creates a std::array by taking the initializer list
		// and "unwrapping" it with std::index_sequence.
		return std::array<T, N>{ *(t.begin() + Ns) ... };
	}

	template<typename Type, std::size_t Size>
	std::array<Type, Size> make_array(std::initializer_list<Type> t)
	{
		if (Size > t.size())
		{
			throw std::out_of_range("Array is too big!");
		}
		return make_array_impl<Type, Size>(t, std::make_index_sequence<Size>());
	}



	// Make a vector with any number of components.
	template<typename T>
	Vector(std::initializer_list<T> elems)
	{
		e = make_array<T, SIZE>(elems);
	}

	template<class... Args>
	Vector(Args&&... args)
	{
		Vector({std::forward<Args>(args)...});
	}



	TYPE x() const {return e.at(0);};
	TYPE y() const {return e.at(1);};
	TYPE z() const {return e.at(2);};

	// enable only if size is >= 4
	TYPE w() const requires (SIZE >= 4) {return e.at(3);};




	constexpr Vector operator-() const
	{
		Vector<TYPE,SIZE> newVec;
		newVec.e = this->e;
		std::transform(newVec.e.begin(), newVec.e.end(), std::minus<TYPE>());
		return newVec;
	}

	TYPE operator[](int i) const { return e[i]; }
	TYPE& operator[](int i) { return e[i]; }


	constexpr Vector& operator+=(const Vector& rhs)
			requires(e.size() == rhs.e.size())
			{
		std::transform(e.begin(),e.end(),
					   rhs.begin, rhs.end(),[](TYPE& a, TYPE& b){
			return a+=b;
		});
		return *this;

	}

	constexpr Vector& operator-=(const Vector& rhs)
		requires(e.size() == rhs.e.size())
		{
			std::transform(e.begin(),e.end(),
						   rhs.begin, rhs.end(),[](TYPE& a, TYPE& b){
						return a-=b;
					});
			return *this;
	}

};
#endif //RAYTRACING_WEEKEND_MATH_H
