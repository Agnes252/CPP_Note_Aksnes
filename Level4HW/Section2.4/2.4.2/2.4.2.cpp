/*
    2.4.2.cpp

    Test program of the class Point, Line and Circle with main() function.

    Test global operator overloading: << 
    
    2025.3.18
    Ruochen Bao
*/

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    // test Point class
    Point p1(1,1);
    Point p2(4,5);
    double factor = 2.0; 
    Point p3;

    cout << "test Point class:" << endl;
    cout << p1.ToString() << ", " << p2.ToString() << endl;
    cout << "factor:" << factor << endl;

    // point class member operator overloading
    p3 = -p1;
    cout << "-" << p1.ToString() << "=" << p3.ToString() << endl;

    p3 = p1*factor;
    cout << p1.ToString() << "*" << factor << "=" << p3.ToString() << endl;

    p3 = p1 + p2;
    cout << p1.ToString() << "+" << p2.ToString() << "=" << p3.ToString() << endl;

    cout << p1.ToString() << "==" << p2.ToString() << ":" << (p1==p2) << endl;

    p3 = p1;
    cout << "p3 = p1, then p3 =" << p3.ToString() << endl;

    p3 *= factor;
    cout << "p3 *= factor, then p3 =" << p3.ToString() << endl;

    // Test << operator in Point class.
	cout << "Test << operator. p1:" << p1 << endl << endl;

    // test Line class
    Line line1;
    Line line2(p1,p2);
    Line line3(p1*2, p2*2);

    cout << "test Line class:" << endl;
    cout << line1.ToString() << ", " << line2.ToString() << ", " << line3.ToString() <<endl;

    // line class member operator overloading
    line1 = line2 = line3; // chain assignment
    cout << "line1 = line2 = line3, then line1 =" << line1.ToString() << endl 
        << "line2=" << line2.ToString() << endl << "line3=" << line3.ToString() << endl;

    // Test << operator in Line class.
	cout << "Test << operator. line1:" << line1 << endl << endl;

    // test Circle class
    Circle c1; //c1: center point : (0,0), radius = 0
    Circle c2(p1,2); //c2: center point : p1, radius = 2
    Circle c3(p2,3); //c2: center point : p2, radius = 3

    cout << "test Circle class:" << endl;
    cout << c1.ToString() << ", " << c2.ToString() << ", " << c3.ToString() <<endl;

    c1 = c2 = c3; // chain assignment
    cout << "c1 = c2 = c3, then c1 =" << c1.ToString() << endl
    << "c2=" << c2.ToString() << endl << "c3=" << c3.ToString() << endl;

    // Test << operator in Circle class.
	cout << "Test << operator. c1:" << c1 << endl << endl;

    return 0;
}