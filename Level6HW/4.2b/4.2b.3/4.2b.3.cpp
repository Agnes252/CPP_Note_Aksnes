/*
    4.2b.3.cpp

    Test PointArray class.

    2025.3.27
    Ruochen Bao
*/

#include "PointArray.hpp"
#include "Array.cpp"
#include "ArrayException.hpp"
#include <iostream>
using namespace std;

int main()
{
    // Test default constructor.
	PointArray parray0;
	cout << "PointArray0: " << endl << "size = " << parray0.Length() << endl;

    // Test constructor with size as input.
	PointArray parray1(3);
	cout << "PointArray1: " << endl;
	for (int i = 0; i < parray1.Size(); i++)
	{
		parray1[i] = Point(i, i);
		cout << parray1[i] << endl;
	}

    // Test copy constructor.
	PointArray parray2(parray1);
	cout << "NumericArray2: " << endl;
	for (int i = 0; i < parray2.Size(); i++)
	{
		cout << parray2[i] << endl;
	}

    // Test assignment operator.
	PointArray parray3 = parray2;
	cout << "NumericArray3: " << endl;
	for (int i = 0; i < parray3.Size(); i++)
	{
		cout << parray3[i] << endl;
	}

    // Test Length()
    cout << "Length of NumericArray3:" << parray3.Length() << endl;
}