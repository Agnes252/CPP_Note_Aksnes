/*
    Circle.cpp

    Implementation of member functions in Circle.hpp for class "Circle"

    2025.3.15
    Ruochen Bao
*/

#define _USE_MATH_DEFINES // define before cmath
#include <cmath>
#include "Circle.hpp"
#include "Point.hpp"
#include <sstream>

Circle::Circle()
{
}

Circle::Circle(const Point& newcenter, double newradius): m_center(newcenter), m_radius(newradius)
{
}

Circle::Circle(const Circle& circle): m_center(circle.m_center), m_radius(circle.m_radius)
{
}

Circle::~Circle()
{
}

Point Circle::CentrePoint() const
{
    return m_center;
}

double Circle::Radius() const
{
    return m_radius;
}

void Circle::CentrePoint(const Point& newcenter)
{
    m_center = newcenter;
}

void Circle::Radius(double newradius)
{
    m_radius = newradius;
}

double Circle::Diameter() const
{
    return 2.0 * m_radius;
}

double Circle::Area() const
{
    return M_PI * pow(m_radius,2);
}

double Circle::Circumference() const
{
    return 2*M_PI*m_radius;
}

string Circle::ToString() const
{
    stringstream stream;
    stream<<"Circle: "<<m_center.ToString()<<","<<" r = "<<m_radius;
    return stream.str();
}

// operator assignment overloading
Circle& Circle::operator = (const Circle& source)
{
    if (this == &source)
        return *this;
    
    m_center = source.m_center;
    m_radius = source.m_radius;
    return *this;
}

// friend operator overloading
ostream& operator << (ostream& os, const Circle& circle)
{
    os << circle.m_center << ", r=" << circle.m_radius << endl;
    return os;
}