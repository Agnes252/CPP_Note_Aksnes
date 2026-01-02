/*
    3.5.4.cpp

    Abstract functions.
    
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
    Shape* shapes[10];
	shapes[0] = new Line;
	shapes[1] = new Point;
	shapes[2] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));
	shapes[3] = new Circle(Point(0.0, 0.0), 1.0);
	for (int i = 0; i != 4; i++) shapes[i]->Draw();
	for (int i = 0; i != 4; i++) delete shapes[i];

	//Shape sp; 
    // Cannot create an instance of the Shape class.

    return 0;
}