/*
    PointArray.cpp

    Implementations of PointArray.hpp

    2025.3.28
    Ruochen Bao
*/

#include "PointArray.hpp"
#include "Point.hpp"

// Constructors
PointArray::PointArray() : Array()
{ 
}

PointArray::PointArray(int size) : Array(size)
{
}

PointArray::PointArray(const PointArray& pp) : Array(pp)
{ 
}

// Destructor
PointArray::~PointArray()
{ 
}

// assignment operator
PointArray& PointArray::operator = (const PointArray& source)
{ 
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Array<Point>::operator = (source);

	return *this;
}

double PointArray::Length() const
{
	double length = 0.0;

	for (int i = 0; i < Array<Point>::Size() - 1; i ++)
	{
		length += (Array<Point>:: operator [] (i)).Distance(Array<Point>:: operator [] (i + 1));
	}

	return length;
}