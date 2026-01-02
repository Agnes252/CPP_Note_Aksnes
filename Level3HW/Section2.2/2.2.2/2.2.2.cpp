/*
    2.2.2.cpp 
    Test program of the Class Point with main() function.
    
    Modifications:
    2025.3.15 Amplified with Distance outputs.
     
    2025.3.15
    Ruochen Bao
*/

#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    double x1, y1; 
    double x2, y2; // x-,y-coordinates of the point

    // construct Point objects
    Point point1;
    Point point2;

    // get user input of point1(x,y)
    cout << "Please input point1 coordination in this format:" << endl << "x y" << endl;

    if (!(cin >> x1 >> y1)) // get & check inputs
	{
		cout << "Input Error." << endl;
		return 1;
	}

    // set the coordinates
    point1.SetX(x1);
    point1.SetY(y1);

    // print the coordinates
    cout << "X:" << point1.GetX() << " Y:" << point1.GetY() << endl;

    // print point description
    cout << point1.ToString() << endl << endl;




    // get user input of point2(x,y)
    cout << "Please input point2 coordination in this format:" << endl << "x y" << endl;

    if (!(cin >> x2 >> y2)) // get & check inputs
	{
		cout << "Input Error." << endl;
		return 1;
	}

    // set the coordinates
    point2.SetX(x2);
    point2.SetY(y2);

    // Print the distance between (0,0) and p2(x2, y2)
    cout << "The distance between (0,0) and " << point2.ToString()
        << ":" << point2.DistanceOrigin() << endl;
    
    // Print the distance between p1(x1,x2) and p2(x2, y2)
    cout << "The distance between " << point1.ToString() << " and " << point2.ToString()
        << ":" << point2.Distance(point1) << endl;    

    return 0;
}