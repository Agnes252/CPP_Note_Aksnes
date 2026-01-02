/*
    NumericArray.hpp

    Header file for an NumericArray class,
    derived from class Array.
    
    2025.3.27
    Ruochen Bao
*/

#ifndef NumericArray_HPP
#define NumericArray_HPP

#include "Array.hpp"

// derived from Array<T>
template <typename T> 
class NumericArray : public Array<T>
{
public:
	// Constructors
	NumericArray();
	NumericArray(int size);
	NumericArray(const NumericArray<T>& arr);

	// Destructor
	~NumericArray();

	// Member operator overloading
	NumericArray<T>& operator = (const NumericArray<T>& source);
	NumericArray<T> operator * (const T& factor) const;
	NumericArray<T> operator + (const NumericArray<T>& arr) const;

	// Numeric functionality
	T DotProduct(const NumericArray<T>& arr) const;
};

#ifndef NumericArray_cpp // Must be the same name as in source file #define
#include "NumericArray.cpp"
#endif

#endif