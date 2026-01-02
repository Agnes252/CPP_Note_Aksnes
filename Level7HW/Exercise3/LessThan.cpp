/*
    LessThan.cpp
    Implementations of LessThan.hpp

    2025.4.1
    Ruochen Bao
*/

#ifndef LessThan_CPP
#define LessThan_CPP

#include "LessThan.hpp"

// constructors
template <typename T>
LessThan<T>::LessThan()
{ // Default constructor.
}

template <typename T>
LessThan<T>::LessThan(const T& t) : limit(t)
{ // Constructor with the limit value as input.
}

template <typename T>
LessThan<T>::LessThan(const LessThan<T>& source) : limit(source.limit)
{ // Copy constructor.
}

template <typename T>
LessThan<T>::~LessThan()
{ // Destructor.
}

template <typename T>
LessThan<T>& LessThan<T>::operator = (const LessThan<T>& source)
{ // Assignment operator
	if (this == &source)
	{
		return *this;
	}

	limit = source.limit;
	return *this;
}

template <typename T>
int LessThan<T>::operator () (const T& t) const
{ // () operator
	return (t < limit);
}

#endif