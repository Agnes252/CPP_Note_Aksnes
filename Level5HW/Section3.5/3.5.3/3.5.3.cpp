/*
    3.5.3.cpp

    Virtual destructors.
    
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
    Shape* shapes[3];
    shapes[0]=new Shape;
    shapes[1]=new Point;
    shapes[2]=new Line;


    // test destructors
    for (int i=0; i!=3; i++) 
    {
        delete shapes[i];
        cout<<endl;
    }
    
    /*
    When NOT declaring Virtual destructor in Shape:
        Shape destructor called once for each shapes[i].

     When declaring Virtual destructor in Shape:
        Point destructor called 0/1/2 times.
        Shape destructor called 1/1/3 times.
        Line destructor called 0/0/1.
    */

    return 0;
}