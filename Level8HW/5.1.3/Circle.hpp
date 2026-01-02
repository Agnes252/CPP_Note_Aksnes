/*
    Circle.hpp

    Header file for Circles with a center point and a radius.
    Point has x- and y-coordinates.

    2025.3.18
    Ruochen Bao
*/


#ifndef Circle_HPP
#define Circle_HPP

#include "Shape.hpp"
#include "Point.hpp"
#include <iostream>
using namespace std;

class Circle : public Shape
{
private:
    Point m_center; // center point
    double m_radius; // radius

public:
    // Constructors
    Circle(); //default constructor
    Circle(const Circle& circle); //copy constructor
    Circle(const Point& newcenter, double newradius); // constructor that accepts radius and center point

    // Destructor
    ~Circle();

    // Accessing functions
    Point CentrePoint() const; // The center
    void CentrePoint(const Point& newCenter);
    double Radius() const; // The radius
    void Radius(double newR);

    // operator assignment overloading
    Circle& operator = (const Circle& source); // Assignment operator.

    // friend <<
    friend ostream& operator << (ostream& os, const Circle& circle);

    void Draw() const;
    string ToString() const; // string description of the circle

};
		  

#endif
