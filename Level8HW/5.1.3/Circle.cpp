/*
    Circle.cpp

    Implementation of member functions in Circle.hpp for class "Circle"

    Constant functions, arguments and passing by reference are set if applicable.

    2025.3.15
    Ruochen Bao
*/

#define _USE_MATH_DEFINES // define before cmath
#include <cmath>
#include "Circle.hpp"
#include "Point.hpp"
#include <sstream>

Circle::Circle() : Shape()
{
    m_center = Point(0, 0);
    m_radius = 1.0;

}

Circle::Circle(const Point& newcenter, double newradius): Shape()
{
    m_center = newcenter;
    m_radius = newradius;
}

Circle::Circle(const Circle& circle): Shape(circle)
{
    m_center = circle.m_center;
    m_radius = circle.m_radius;
}

Circle::~Circle()
{
}

Point Circle::CentrePoint() const
{
	return m_center;
}

void Circle::CentrePoint(const Point& newCenter)
{
	m_center = newCenter;
}

double Circle::Radius() const
{
	return m_radius;
}

void Circle::Radius(double newR)
{
	m_radius = newR;
}

string Circle::ToString() const
{
    stringstream stream;
    std::string s = Shape::ToString();
    stream<<"Circle: "<<m_center.ToString()<<","<<" r = "<<m_radius<<","<<s;
    return stream.str();
}

// operator assignment overloading
Circle& Circle::operator = (const Circle& source)
{
    if (this == &source)
        return *this;
    
    // Call base class assignment
    Shape::operator = (source);

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

void Circle::Draw() const
{
    cout << "Draw a circle." << endl;
}