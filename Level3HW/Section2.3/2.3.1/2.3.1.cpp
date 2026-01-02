/*
    2.3.1.cpp 
    Test program of the Class Point with main() function.
    
    Modifications:
    2025.3.15 Amplified with Distance outputs.
        print when constructor and destructor functions are called.
     
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

    // construct Point object
    Point point2(x2,y2);

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

    /*
    Findings:
        1,copy constructor is called once.
        2,constructor that accepts coordinates is called twice.
        3,destructor is called three times.
        4,# of constructor call = # of destructor call

    Conclusion:
        We can derive two things from these results:
        1. When calling the Distance() function, the input point is copied (call by value).
        2. You will get the copy constructor 'for free' when you do not create one yourself
    */
}