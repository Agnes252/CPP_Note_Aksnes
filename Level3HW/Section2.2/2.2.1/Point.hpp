/*
    Point.hpp

    Header file for Points in two dimensions. Point has x- and y-coordinates.

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
    Point(); 

    // Destructors
    ~Point();

    // Accessing functions
    double GetX(); // getter function for X-coordinate
    double GetY(); // getter function for Y-coordinate

    // Modifiers
    void SetX(double newxval); // setter function for X-coordinate 
    void SetY(double newyval); // setter function for Y-coordinate

    string ToString(); // string description of the point
};

#endif
