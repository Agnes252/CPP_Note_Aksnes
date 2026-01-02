/*
    3.5.5.cpp

    Template Method Pattern (Print()).
    
    2025.3.23
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
	
    // Print() can be called even derived class do NOT have Print(), only have ToString().
    for (int i = 0; i != 4; i++) shapes[i]->Print();
	for (int i = 0; i != 4; i++) delete shapes[i];

    return 0;
}