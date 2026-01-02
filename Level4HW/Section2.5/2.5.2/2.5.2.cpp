/*
    2.5.2.cpp

    Create array of pointers using different constructors.

    2025.3.19
    Ruochen Bao
*/

#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int size = 3; // number of elements in the array of pointers
    Point** parr = new Point*[size]; // create an array of pointers
    Point* p_source = new Point(1.0, 1.0); // point for copy constructor

    // initialise 3 elements
    parr[0] = new Point();
    parr[1] = new Point(2.0, 3.0);
    parr[2] = new Point((*p_source));
    delete p_source;
    p_source = nullptr; // avoid a dangling pointer

    // Print each element in the array
	for (int i = 0; i < 3; i++)
	{
		cout << *parr[i] << endl;
	}

	// Delete each element in the array
	for (int i = 0; i < 3; i++)
	{
		delete parr[i];
	}

    // delete the array
	delete[] parr;

    return 0;
}