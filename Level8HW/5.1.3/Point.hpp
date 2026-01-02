/*
    Point.hpp

    Header file for Points in two dimensions.
    Point has x- and y-coordinates.

    2025.3.24
    Ruochen Bao
*/

#ifndef Point_HPP
#define Point_HPP

#include "Shape.hpp"
#include <iostream>
using namespace std;

class Point : public Shape
{
private:
    double m_x; // X coordinate
    double m_y; //Y coordinate

public:
    // Constructors
    Point(); //default constructor
    Point(const Point& point); //copy constructor
    Point(double newxval, double newyval); // constructor that accepts coordinates
    explicit Point(double value);

    // Destructors
    virtual ~Point();

    // Accessing functions
	double X() const; // The x-coordinate
	void X(double newX);
	double Y() const; // The y-coordinate
	void Y(double newY);

    // Member operator overloading
    Point& operator = (const Point& source); // Assignment operator.

    // friend <<
    friend ostream& operator << (ostream& os, const Point& p); // Send to ostream.

    // functionalities
    void Draw() const;
    string ToString() const; // string description of the point
    double Distance(const Point& p) const; 
};

#endif
