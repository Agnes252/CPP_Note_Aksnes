/*
    NumericArray.cpp

    Implementation of member functions in NumericArray.hpp

    2025.3.27
    Ruochen Bao
*/

#ifndef NumericArray_CPP
#define NumericArray_CPP

#include "NumericArray.hpp"
#include "OutOfBoundsException.hpp"

// Constructors
template <typename T>
NumericArray<T>::NumericArray() : Array<T>::Array()
{ 
}

template <typename T>
NumericArray<T>::NumericArray(int size) : Array<T>::Array(size)
{
}

template <typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& arr) : Array<T>::Array(arr)
{ 
}

// Destructor
template <typename T>
NumericArray<T>::~NumericArray()
{
}

// Member operator overloading
// Assignment operator
template <typename T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)
{ 
	// Exit if same object
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Array<T>::operator = (source);
	
	return *this;
}

// * operator
template <typename T>
NumericArray<T> NumericArray<T>::operator * (const T& factor) const
{
	NumericArray<T> result(*this); // construct result
	
	for (int i = 0; i < result.Size(); i++)
	{
		result[i] *= factor;
	}

	return result;
}

// + operator
template <typename T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& arr) const
{
	if (Array<T>::Size() != arr.Size())
	{
		throw OutOfBoundsException();
	}

	NumericArray<T> result(*this);

	for (int i = 0; i < result.Size(); i++)
	{
		result[i] += arr[i];
	}

	return result;
}

// Numeric functionality
// Dot product.
template <typename T>
T NumericArray<T>::DotProduct(const NumericArray<T>& arr) const
{ 
	if (Array<T>::Size() != arr.Size())
	{
		throw OutOfBoundsException();
	}

	T result = T(); // initialise result to T()
	
	for (int i = 0; i < Array<T>::Size(); i++)
	{
		result += (Array<T>::operator [] (i) * arr[i]);
	}

	return result;
}


#endif