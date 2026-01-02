/*
    4.2b.2.cpp

    Test NumericArray class.

    2025.3.27
    Ruochen Bao
*/

#include "NumericArray.cpp"
#include "Array.cpp"
#include "ArrayException.hpp"
#include <iostream>
using namespace std;

int main()
{
    // Test default constructor.
	NumericArray<int> array0;
	cout << "NumericArray0: " << endl << "size = " << array0.Size() << endl;

    // Test constructor with size as input.
	NumericArray<int> array1(2);
	array1[0] = 1;
	array1[1] = 2;
	cout << "NumericArray1: " << endl << array1[0] << "," << array1[1] << endl;

    // Test copy constructor.
	NumericArray<int> array2(array1);
	cout << "NumericArray2: " << endl << array2[0] << "," << array2[1] << endl;

    // Test assignment operator.
	NumericArray<int> array3 = array1;
	cout << "NumericArray3: " << endl;
	for (int i = 0; i < array3.Size(); i++)
	{
		cout << array3[i] << endl;
	}

    // Test * operator.
    int factor = 2;
	NumericArray<int> array4 = array2 * factor;
	cout << "NumericArray4: " << endl;
	for (int i = 0; i < array4.Size(); i++)
	{
		cout << array4[i] << endl;
	}

    // Test + operator
	NumericArray<int> array5;
    try
	{
        array5 = array1 + array2; // both size = 2
        cout << "NumericArray5: " << endl;
        for (int i = 0; i < array5.Size(); i++)
        {
            cout << array5[i] << endl;
        }
    }
    catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}

    // Test dot product and case with incompatible size.
	int dot_product;
	cout << "dot_product: " << endl;
	dot_product = array1.DotProduct(array2);
	cout << dot_product << endl;
	
    // error case of dot product
    NumericArray<int> array6(5);
	int dot_product2;
	cout << "dot_product2: " << endl;
	try
	{
		dot_product2 = array1.DotProduct(array6); 
        // index incompatible: array1(2), array6(5)
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}

}