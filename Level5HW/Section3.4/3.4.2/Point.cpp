/*
    Point.cpp

    Implementation of member functions in Point.hpp for class "Point"
    
    2025.3.22
    Ruochen Bao
*/

#include "Point.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

Point::Point() : Shape() // specify base class constructor
{
    m_x = 0.0;
    m_y = 0.0;
}

Point::Point(const Point& point) : Shape(point)
{
    m_x = point.m_x; 
    m_y = point.m_y;  // copy constructor
}


Point::Point(double newxval, double newyval) : Shape() 
{
    m_x = newxval;
    m_y = newyval; // Constructor that accepts x- and y-coordinates
}

Point::Point(double value) : Shape()  
{
    m_x = value;
    m_y = value; // constructor that accepts value
}

Point::~Point() // Default destructor
{
}

double Point::X() const
{
    return m_x; 
}

double Point::Y() const
{
    return m_y; 
}

void Point::X(double newxval)
{
    m_x = newxval;
}

void Point::Y(double newyval)
{
    m_y = newyval;
}

string Point::ToString() const
{
    stringstream stream;
    stream << "Point:(" << m_x << "," << m_y << ")";
    return stream.str();
}

double Point::Distance() const
{
    return sqrt(pow(m_x,2) + pow(m_y,2));
}

double Point::Distance(const Point& p) const
{
    return sqrt(pow(m_x - p.m_x , 2) + pow(m_y - p.m_y , 2));
}


// Member operator overloading
Point Point::operator - () const
{
    return Point(-m_x, -m_y);
}

Point Point::operator * (double factor) const
{
    return Point(m_x * factor, m_y * factor);
}

Point Point::operator + (const Point& p) const
{
    return Point(m_x + p.m_x, m_y + p.m_y);
}

bool Point::operator == (const Point& p) const
{
    return (m_x == p.m_x) && (m_y == p.m_y);
}

Point& Point::operator = (const Point& source)
{
	// Avoid doing assign to myself
	if (this == &source)
		return *this;

    // Call base class assignment
    Shape::operator = (source);
    
	m_x = source.m_x;
	m_y = source.m_y;
	return *this;
}

Point& Point::operator *= (double factor)
{
	m_x *= factor;
	m_y *= factor;
	return *this;
}

// friend operator overloading: <<
ostream &operator << (ostream& os, const Point& p)
{
	os << "Point(" << p.m_x << "," << p.m_y << ")"<<endl; // Send to ostream
	return os;
}
