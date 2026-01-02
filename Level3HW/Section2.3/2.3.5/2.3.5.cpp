/*
    2.3.5.cpp

    Test program of the class Line with main() function.

    Constant functions, arguments and passing by reference are set if applicable.
    
    2025.3.15
    Ruochen Bao
*/

#include "Line.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	double x1, y1;
	double x2, y2; // coordinates of start & end points

	// get user input of start point coordination
	cout << "Please input start point coordination in this format:" << endl << "x y" << endl;

	if (!(cin >> x1 >> y1))
	{
		cout << "Input Error." << endl;
		return 1;
	}

	// get user input of end point coordination
	cout << "Please input end point coordination in this format:" << endl << "x y" << endl;


	if (!(cin >> x2 >> y2))
	{
		cout << "Input Error." << endl;
		return 1;
	}

	// Create the start point and end point.
	const Point p1(x1, y1);
	const Point p2(x2, y2);

	// Create the line object.
	Line line(p1, p2);

	cout << line.ToString() << ", " << "the length is " << line.Length() << "." << endl;	

    return 0;
}