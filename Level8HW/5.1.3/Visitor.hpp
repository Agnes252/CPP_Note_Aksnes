/*
    Visitor.hpp

    Header file for class Visitor to move the shape object.

    2025.4.5
    Ruochen Bao
*/

#ifndef Visitor_HPP
#define Visitor_HPP

#include <boost/variant/static_visitor.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

class Visitor : public boost::static_visitor<void>
{
private:
	double m_dx; // x-coordinate shift
	double m_dy; // y-coordinate shift

public:
	// Constructors and destructor
	Visitor(); 
	Visitor(const Visitor& source); 
	Visitor(double xValue, double yValue); 
	~Visitor();

	// Member operator overloading
	Visitor& operator = (const Visitor& source); // Assignment operator
	void operator () (Point& p) const; // () operator for Point
	void operator () (Line& p) const; // () operator for Line
	void operator () (Circle& p) const; // () operator for Circle
};

#endif