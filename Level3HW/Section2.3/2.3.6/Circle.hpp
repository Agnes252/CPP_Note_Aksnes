/*
    Circle.hpp

    Header file for Circles with a center point and a radius.
    Point has x- and y-coordinates.

    Constant functions, arguments and passing by reference are set if applicable.


    2025.3.15
    Ruochen Bao
*/


#ifndef Circle_HPP
#define Circle_HPP

#include "Point.hpp"
#include <iostream>
using namespace std;

class Circle
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
    Point CentrePoint() const; // getter function for center
    double Radius() const; // getter function for radius

    // Modifiers
    void CentrePoint(const Point& newcenter); // setter function for center
    void Radius(double newradius); // setter function for radius

    // Calculation functions
    double Diameter() const; // Calculate the diameter
    double Area() const; // Calculate the area
    double Circumference() const; // Calculate the Circumference

    string ToString() const; // string description of the circle
};

#endif
