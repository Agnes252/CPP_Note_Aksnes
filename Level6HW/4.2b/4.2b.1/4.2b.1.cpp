/*
    4.2b.1.cpp

    Static variable for Array default size.

    2025.3.25
    Ruochen Bao
*/

#include "Array.cpp"
#include "ArrayException.hpp"
#include <iostream>
using namespace std;

int main()
{
    Array<int> intArray1;
    Array<int> intArray2;
    Array<double> doubleArray;

    // static_m_size (default size) set to 10 in Array.hpp
    cout<<intArray1.DefaultSize()<<endl; // 10
    cout<<intArray2.DefaultSize()<<endl; // 10
    cout<<doubleArray.DefaultSize()<<endl; // 10
    
    intArray1.DefaultSize(15); // default size of intArray1 is set to 15
    
    cout<<intArray1.DefaultSize()<<endl; //15
    // Static data member is independent of any particular object of the class Array<int>,
	// so when the default size of intArray1 is set to 15, the default size of intArray2 is also 15.
    cout<<intArray2.DefaultSize()<<endl; //15
    // doubleArray is an instance of class Array<double> rather than Array<int>,
    // therefore the default size of doubleArray is still 10.
    cout<<doubleArray.DefaultSize()<<endl; //10

    return 0;
}

