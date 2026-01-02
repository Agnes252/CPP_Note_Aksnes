/*
    Point.hpp

    Header file for Points in two dimensions.
    Point has x- and y-coordinates.
    
    Operator overloading applied.

    2025.3.18
    Ruochen Bao
*/

#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

class Point
{
private:
    double m_x; // X coordinate
    double m_y; //Y coordinate

public:
    // Constructors
    Point(); //default constructor
    Point(const Point& point); //copy constructor
    Point(double newxval, double newyval); // constructor that accepts coordinates

    // Destructors
    ~Point();

    // Accessing functions
    double X() const; // getter function for X-coordinate
    double Y() const; // getter function for Y-coordinate

    // Modifiers
    void X(double newxval); // setter function for X-coordinate 
    void Y(double newyval); // setter function for Y-coordinate

    string ToString() const; // string description of the point

    // Distance functions
    double Distance() const; // Calculate the distance to the origin (0, 0)
    double Distance(const Point& p) const; // Calculate the distance between two points

    // Member operator overloading
    Point operator - () const; // Negate the coordinates.
    Point operator * (double factor) const; // Scale the coordinates.
    Point operator + (const Point& p) const; // Add coordinates.
    bool operator == (const Point& p) const; // Equally compare operator.
    Point& operator = (const Point& source); // Assignment operator.
    Point& operator *= (double factor); // Scale the coordinates & assign.
};

ostream& operator << (ostream& os, const Point& p); // Send to ostream.

#endif
