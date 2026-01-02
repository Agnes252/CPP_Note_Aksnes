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

#include "Shape.hpp"
#include "Point.hpp"
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
	Point P1() const; // The start point
	void P1(const Point& newP1);
	Point P2() const; // The end point
	void P2(const Point& newP2);

    // member operator overloading
    Line& operator = (const Line& source); // Assignment operator.

    // friend << function
    friend ostream& operator << (ostream& os, const Line& line); // Send to ostream.
    
    void Draw() const;
    string ToString() const; // string description of the line
    double Length() const; // Calculate the line length

};

#endif