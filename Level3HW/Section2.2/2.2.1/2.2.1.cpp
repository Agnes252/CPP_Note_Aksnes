/*
    2.2.1.cpp 
    Test program of the Class Point with main() function.
     
    2025.3.15
    Ruochen Bao
*/

#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    double newxval, newyval; // x-,y-coordinates of the point

    // get user input of (x,y)
    cout << "Please input point coordination in this format:" << endl << "x y" << endl;

    if (!(cin >> newxval >> newyval)) // get & check inputs
	{
		cout << "Input Error." << endl;
		return 1;
	}

    // construct a Point object
    Point point;

    // set the coordinates
    point.SetX(newxval);
    point.SetY(newyval);

    // print the coordinates
    cout << "X:" << point.GetX() << " Y:" << point.GetY() << endl;

    // print point description
    cout << point.ToString() << endl;

    return 0;
}