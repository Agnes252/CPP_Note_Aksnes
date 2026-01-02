/*
    2.5.1.cpp

    Dynamically create Point objects and Point array.

    2025.3.19
    Ruochen Bao
*/

#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    double x=2.0, y=3.0;

    // constructors with new
    Point* p1 = new Point(); // default constructor

    Point* p2 = new Point(x, y); // constructor with coordinates

    p1 = new Point(*p2); // pointer must be dereferenced before passed to the copy constructor

    // call Distance() & cout points on the pointers
    cout << "p1:" << (*p1) << "p2:" << (*p2) << "Distance:"<< (*p1).Distance((*p2)) << endl;

    delete p1, p2;

    // create an array of points
    cout << "Please input the size of the Point array." << endl;

    int size; // user input: size of the Point array
    if (!(cin >> size))
	{
		cout << "Input Error." << endl;
		return 1;
	}

	//Point pp[size]; // Compiler error.

	Point* pp = new Point[size]; // Can only use default constructor.
	delete[] pp; // the square bracket!

    cout << "Bye my Point array..." << endl;
    return 0;
}