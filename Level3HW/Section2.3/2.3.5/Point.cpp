/*
    Point.cpp

    Implementation of member functions in Point.hpp for class "Point"

    Constant functions, arguments and passing by reference are set if applicable.
    
    2025.3.15
    Ruochen Bao
*/

#include "Point.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

Point::Point() // Default constructor
{
}

Point::Point(const Point& point) : m_x(point.m_x), m_y(point.m_y) // copy constructor
{
}

Point::Point(double newxval, double newyval) : m_x(newxval), m_y(newyval) // Constructor that accepts x- and y-coordinates
{
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