/*
    Point.hpp

    Header file for Points in two dimensions.
    Point has x- and y-coordinates.

    Constant functions, arguments and passing by reference are set if applicable.

    Modifications:
    2025.3.15 Getter and Setter functions are turned into normal inline and default inline functions, separately.

    2025.3.15
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

    // Getter functions
    double X() const; // getter function for X-coordinate
    double Y() const; // getter function for Y-coordinate

    // Setter functions: default inline
    void X(double newxval) {m_x = newxval;}; // setter function for X-coordinate 
    void Y(double newyval) {m_y = newyval;}; // setter function for Y-coordinate

    string ToString() const; // string description of the point

    // Distance functions
    double Distance() const; // Calculate the distance to the origin (0, 0)
    double Distance(const Point& p) const; // Calculate the distance between two points
};

// getter functions: normal inline
inline double Point::X() const { return m_x; }
inline double Point::Y() const { return m_y; }

#endif
