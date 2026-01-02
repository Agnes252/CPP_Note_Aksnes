/*
    Line.hpp

    Header file for Line with start point and end point, both are Point object.

    Member assignment operator added.

    << friend function
    
    2025.3.18
    Ruochen Bao
*/

#ifndef Line_HPP
#define Line_HPP

#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>
using namespace std;

class Line : public Shape
{
private:
    Point p1; // start point
    Point p2; // end point

public:
    // Constructors
    Line(); //default constructor
    Line(const Line& line); //copy constructor
    Line(const Point& newp1, const Point& newp2); // constructor that accepts 2 points

    // Destructor
    virtual ~Line();

    // Accessing functions
    const Point& P1() const; // getter function for X-coordinate
    const Point& P2() const; // getter function for Y-coordinate

    // Modifiers
    void P1(const Point& newp1); // setter function for X-coordinate 
    void P2(const Point& newp2); // setter function for Y-coordinate

    string ToString() const; // string description of the line
    double Length() const; // Calculate the line length

    // member operator overloading
    Line& operator = (const Line& source); // Assignment operator.

    // friend << function
    friend ostream& operator << (ostream& os, const Line& line); // Send to ostream.
};

#endif