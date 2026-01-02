/*
    Point.cpp

    Implementation of member functions in Point.hpp for class "Point"
    Getter functions are turned into const functions.

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
    cout << "Default constructor called." << endl; 
}

Point::Point(const Point& point) : x(point.x), y(point.y) // copy constructor
{
    cout << "Copy constructor called." << endl; 
}

Point::Point(double newxval, double newyval) : x(newxval), y(newyval) // Constructor that accepts x- and y-coordinates
{
    cout << "Constructor with coordinates called." << endl; 
}

Point::~Point() // Default destructor
{
    cout << "Default destructor called." << endl; 
}

double Point::X() const
{
    return x; 
}

double Point::Y() const
{
    return y; 
}

void Point::X(double newxval)
{
    x = newxval;
}

void Point::Y(double newyval)
{
    y = newyval;
}

string Point::ToString() const
{
    stringstream stream;
    stream << "Point:(" << x << "," << y << ")";
    return stream.str();
}

double Point::Distance() const
{
    return sqrt(pow(x,2) + pow(y,2));
}

double Point::Distance(const Point& p) const
{
    return sqrt(pow(x - p.x , 2) + pow(y - p.y , 2));
}