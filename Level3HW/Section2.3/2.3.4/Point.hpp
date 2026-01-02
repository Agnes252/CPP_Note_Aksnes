/*
    Point.hpp

    Header file for Points in two dimensions.
    Point has x- and y-coordinates.
    
    Modifications:
    2025.3.15 Amplified with Distance functions.
        Add texts in constructor and destructor functions.
        Add two constructor functions. 

        Distance() now call by reference. 
        
        Functions renamed: X(), Y(): getter & setter. Only 1 Distance(). 

        Getter functions are turned into const functions.


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
    double x; // X coordinate
    double y; //Y coordinate

public:
    // Constructors
    Point(); //default constructor
    Point(const Point& point); //copy constructor
    Point(double newxval, double newyval); // constructor that accepts coordinates

    // Destructors
    ~Point();

    // Function overloading
    // Accessing functions & Modifiers
    double X() const; // getter function for X-coordinate
    double Y() const; // getter function for Y-coordinate
    void X(double newxval); // setter function for X-coordinate 
    void Y(double newyval); // setter function for Y-coordinate

    string ToString() const; // string description of the point

    // Distance functions
    double Distance() const; // Calculate the distance to the origin (0, 0)
    double Distance(const Point& p) const; // Calculate the distance between two points
};

#endif
