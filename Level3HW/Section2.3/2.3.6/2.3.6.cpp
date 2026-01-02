/*
    2.3.6.cpp

    Test program of the class Circle with main() function.

    Constant functions, arguments and passing by reference are set if applicable.
    
    2025.3.15
    Ruochen Bao

*/

#include "Point.hpp"
#include "Circle.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    double x_center, y_center; // coordinates of center point
	double m_r; // radius
	
	// get user input of center point coordination
	cout << "Please input center point coordination in this format:" << endl << "x y" << endl;

	if (!(cin >> x_center >> y_center))
	{
		cout << "Input Error." << endl;
		return 1;
	}

	// get user input of radius
	cout << "Please input radius in this format:" << endl << "r" << endl;

	if (!(cin >> m_r))
	{
		cout << "Input Error." << endl;
		return 1;
	}

	// Create the center
    Point m_center(x_center, y_center);

	// Create the line object.
    Circle m_circle(m_center, m_r);

	cout << m_circle.ToString() << endl;	
    cout << "Diameter: " << m_circle.Diameter() << endl;
	cout << "Area: " << m_circle.Area() << endl;
	cout << "Circumference: " << m_circle.Circumference() << endl;

    return 0;
}