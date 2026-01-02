/*
    2.3.3.cpp 
    Test program of the Class Point with main() function.
    
    Modifications:
    2025.3.15 Amplified with Distance outputs.
        print when constructor and destructor functions are called.
        Functions renamed: X(), Y(): getter & setter. Only 1 Distance().
     
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


    // get user input of point1(x,y)
    cout << "Please input point1 coordination in this format:" << endl << "x y" << endl;

    if (!(cin >> x1 >> y1)) // get & check inputs
	{
		cout << "Input Error." << endl;
		return 1;
	}

    // construct Point object
    Point point1(x1,y1);

    // set the coordinates
    point1.X(x1);
    point1.Y(y1);

    // print the coordinates
    cout << "X:" << point1.X() << " Y:" << point1.Y() << endl;

    // print point description
    cout << point1.ToString() << endl << endl;



    

    // get user input of point2(x,y)
    cout << "Please input point2 coordination in this format:" << endl << "x y" << endl;

    if (!(cin >> x2 >> y2)) // get & check inputs
	{
		cout << "Input Error." << endl;
		return 1;
	}

    // construct Point object
    Point point2(x2,y2);

    // set the coordinates
    point2.X(x2);
    point2.Y(y2);

    // Print the distance between (0,0) and p2(x2, y2)
    cout << "The distance between (0,0) and " << point2.ToString()
        << ":" << point2.Distance() << endl;
    
    // Print the distance between p1(x1,x2) and p2(x2, y2)
    cout << "The distance between " << point1.ToString() << " and " << point2.ToString()
        << ":" << point2.Distance(point1) << endl;    

    return 0;

    /*
    Findings:
        1,constructor that accepts coordinates is called twice.
        2,destructor is called twice.
        4,# of constructor call = # of destructor call

    Conclusion:
        It saves memory to set Distance() as "call by reference". Otherwise a copy will be automatically created.   
    */
}