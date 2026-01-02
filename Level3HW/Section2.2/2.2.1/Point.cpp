/*
    Point.cpp

    Implementation of member functions in Point.hpp for class "Point"

    2025.3.15
    Ruochen Bao
*/

#include "Point.hpp"
#include <sstream>
using namespace std;

Point::Point() // Default constructor
{
}

Point::~Point() // Default destructor
{
}

double Point::GetX()
{
    return m_x; 
}

double Point::GetY()
{
    return m_y; 
}

void Point::SetX(double newxval)
{
    m_x = newxval;
}

void Point::SetY(double newyval)
{
    m_y = newyval;
}

string Point::ToString()
{
    stringstream stream;
    stream << "Point:(" << m_x << "," << m_y << ")";
    return stream.str();
}