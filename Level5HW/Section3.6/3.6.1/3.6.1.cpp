/*
    3.6.2.cpp

    Exception objects.

    2025.3.23
    Ruochen Bao
*/

#include "Array.hpp"
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

    catch (int err)
	{
		if (err == -1)
		{
			cout << "Error: Index out of range." << endl;
		}
	}
}