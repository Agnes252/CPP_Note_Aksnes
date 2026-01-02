/*
    Point.cpp

    Implementation of member functions in Point.hpp for class "Point"
    
    Modifications:
    2025.3.15 Amplified with Distance functions.

    2025.3.15
    Ruochen Bao
*/

#include "Point.hpp"
#include <sstream>
#include <cmath>
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

double Point::DistanceOrigin()
{
    return sqrt(pow(m_x,2) + pow(m_y,2));
}

double Point::Distance(Point p)
{
    return sqrt(pow(m_x - p.m_x , 2) + pow(m_y - p.m_y , 2));
}