/*
    3.6.2.cpp

    Exception handling (array index out of range)

    2025.3.23
    Ruochen Bao
*/

#include "Array.hpp"
#include "ArrayException.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Array arr(5);

    try
    {
        cout << arr[5] << endl; // an exception is thrown
    }

    catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}
}