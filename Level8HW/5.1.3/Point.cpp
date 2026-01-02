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

void Point::X(double newX)
{
	m_x = newX;
}


double Point::Y() const
{
	return m_y;
}

void Point::Y(double newY)
{
	m_y = newY;
}

string Point::ToString() const
{
    stringstream stream;
    std::string s = Shape::ToString();
    stream << "Point:(" << m_x << "," << m_y << "),"<<s;
    return stream.str();
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

// friend operator overloading: <<
ostream &operator << (ostream& os, const Point& p)
{
	os << "Point(" << p.m_x << "," << p.m_y << ")"<<endl; // Send to ostream
	return os;
}

void Point::Draw() const
{
    cout << "Draw a point." <<endl;
}

double Point::Distance(const Point& p) const
{
	return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}