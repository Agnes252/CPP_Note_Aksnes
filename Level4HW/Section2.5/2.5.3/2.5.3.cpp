/*
    2.5.3.cpp

    Create an array class for Point objects that handle memory.

    2025.3.19
    Ruochen Bao
*/

#include "Point.hpp"
#include "Array.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Array arr1; // default arr1[9]
    Array arr2(5); // arr2[4]

    // using setter
    arr2.SetElement(0, Point(1, 2));
    arr2.SetElement(1, Point(3, 4));
    arr2.SetElement(2, Point(5, 6));

    // using getter
    cout << "arr2[1]: " << arr2.GetElement(1) << endl;

    // using []
    arr2[3] = Point(7,8);
    cout << "arr2[3] (using []): " << arr2[3] << endl;

    // assignment operator
    Array arr3 = arr2;
    cout << "arr3[3] (using []): " << arr3[3] << endl;

    // assignment operator const 
    const Array arr(5);
    cout << arr[2] << endl; // operator[] const is called
 
    return 0;
}