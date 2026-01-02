/*
    3.4.2.cpp

    Test Inheritance.
    
    2025.3.22
    Ruochen Bao
*/
#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Shape s; // Create shape.
    Point p(10, 20); // Create point.
    Line l(Point(1,2), Point(3, 4)); // Create line.

    cout<<s.ToString()<<endl; // ID:41
    cout<<p.ToString()<<endl; // Point:(10,20)
    cout<<l.ToString()<<endl; // Line: Point:(1,2)-Point:(3,4)

    cout<<"Shape ID: "<<s.ID()<<endl; // Shape ID: 41
    cout<<"Point ID: "<<p.ID()<<endl; // Point ID: 18467
    cout<<"Line ID: "<<l.ID()<<endl; // Line ID: 19169

    Shape* sp; // Create pointer to a shape variable.
    sp=&p; // Point in a shape variable. Possible?: yes
    cout<<sp->ToString()<<endl; // ID:18467

    // Create and copy Point p to new point.
    Point p2;
    p2=p;
    cout<<p2<<", "<<p2.ID()<<endl; 
    // print: Point(10,20), 18467
    // Conclusion: the ID copied even if you do not call
    // the base class assignment in point

    return 0;
}