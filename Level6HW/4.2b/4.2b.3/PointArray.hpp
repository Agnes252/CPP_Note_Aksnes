/*
    PointArray.hpp

    Header file for PointArray class, derived form Array
    with the template argument set to Point.
    
    2025.3.28
    Ruochen Bao
*/

#ifndef PointArray_HPP
#define PointArray_HPP

#include "Array.cpp"
#include "Point.hpp"

class PointArray : public Array<Point>
{
public:
	// Constructors
	PointArray();
	PointArray(int size);
	PointArray(const PointArray& pp);

	// Destructor
	~PointArray();

	// Member operator overloading
	PointArray& operator = (const PointArray& source);
	
	// Accessing functions
	double Length() const;
};


#endif