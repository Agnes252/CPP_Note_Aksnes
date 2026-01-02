/*
    TestVariant.cpp
    A program that creates a ShapeType variant.
    Also, create a visitor instance to move the shape.

    2025.4.5
    Ruochen Bao
*/

#include <boost/variant.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Visitor.hpp"
#include <string>
#include <iostream>
using namespace std;

// create a typedef for a ShapeType
typedef boost::variant<Point, Line, Circle> ShapeType;

// create a function that ask for ShapeType input and return the type
ShapeType Create()
{
	ShapeType shape;

	// Ask the user for the shape type to create.
	cout << "Please input a number:" << endl << "1:Point; 2:Line; 3:Circle" << endl;
	int choice;
	cin >> choice;

	// Create the requested shape and return.
	switch (choice)
	{
		case 1:
			shape = Point();
			break;
		case 2:
			shape = Line();
			break;
		case 3:
			shape = Circle();
			break;
		default:
            cout << "Invalid input! Returning default shape (Point)." << endl;
			break;
	}

	return shape;
}

int main()
{
	using boost::variant;
	
	ShapeType result = Create();
	cout << result << endl;

    // try to assign a line to the variant "result"
	try
	{
		Line l1 = boost::get<Line>(result);
	}
	catch (boost::bad_get& err)
	{
		cout << "Error: " << err.what() << endl;
	}

	// Move the shape.
	const Visitor visitor(1.0, -1.0);
	boost::apply_visitor(visitor, result); // use global function to move the shape
	cout << result << endl;
}