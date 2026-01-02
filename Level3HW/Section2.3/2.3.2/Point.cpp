/*
    Point.cpp

    Implementation of member functions in Point.hpp for class "Point"
    
    Modifications:
    2025.3.15 Amplified with Distance functions.
        Add texts in constructor and destructor functions.
        Add two constructor functions.
        
        Distance() now call by reference. 

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

double Point::GetX()
{
    return x; 
}

double Point::GetY()
{
    return y; 
}

void Point::SetX(double newxval)
{
    x = newxval;
}

void Point::SetY(double newyval)
{
    y = newyval;
}

string Point::ToString()
{
    stringstream stream;
    stream << "Point:(" << x << "," << y << ")";
    return stream.str();
}

double Point::DistanceOrigin()
{
    return sqrt(pow(x,2) + pow(y,2));
}

double Point::Distance(const Point& p)
{
    return sqrt(pow(x - p.x , 2) + pow(y - p.y , 2));
}