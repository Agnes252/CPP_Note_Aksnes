/*
    2.6.1.cpp
    Using namespaces.

    2025.3.20
    Ruochen Bao
*/

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    // The full namespace for Point class.
	Aksnes::CAD::Point p1;
	Aksnes::CAD::Point p2(2.0, 3.0);
	cout << p1 << ", " << p2 << endl;

	// Using declaration for using a single class (Line).
	using Aksnes::CAD::Line;
	cout << Line(p1, p2);
	
	// Using declaration for a complete namespace (Containers).
	using namespace Aksnes::Containers;
	Array arr(5); 
	arr[0] = p2; // p2 is defined in main()
	cout << arr[0] << endl;

	// Using the Circle class by creating a shorter alias.
	namespace AksCAD = Aksnes::CAD; // nested alias
	using AksCAD::Circle;
	Circle circle(AksCAD::Point(1, 0), 1);
	cout << circle;
}