/*
    4.2a.1.cpp

    Test Template Array class.

    2025.3.24
    Ruochen Bao
*/

#include "Array.cpp"
#include "Point.hpp"
#include <iostream>
using namespace std;

int main()
{
    int size = 3;
    Array<Point> points(size); // create an array of points
    Array<Point> points2(size);

    // Test [] Setter
    points[0] = Point();
    points[1] = Point(2.0);
    points[2] = Point(1.0, 3.0);

    // Test assignment operator
    points2 = points;

    // Test [] getter
    for (int i=0;i<size;i++)
        cout<<points2[i]<<endl;
    
    // test const [] getter
    const Array<Point> points3(points2);
    cout << "points3 elements: "<< points3[0] << ", " << points3[1] << ", " <<  points3[2] << endl;
    
    // Test GetElement & SetElement
    cout << "points elements: "<< points.GetElement(0) << ", " << points.GetElement(1) << ", " << points.GetElement(2) << endl;
    points.SetElement(0, Point(4.0, 4.0));
    cout << "points[0] changed to: "<<points[0]<<endl;

    // Test copy constructor
    Array<Point> points4(points3);
    cout << "points4 copy point3: "<< points3.GetElement(0) << ", " << points3.GetElement(1) << ", " << points3.GetElement(2) << endl;
}