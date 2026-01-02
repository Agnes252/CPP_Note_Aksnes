/*
    Array.hpp

    Header file for an array class for Point objects.
    
    2025.3.23
    Ruochen Bao
*/

#ifndef Array_HPP
#define Array_HPP

#include "Point.hpp"
using namespace std;

class Array
{
private:
    int m_size; // size of the array
    Point* m_data; // a dynamic array of Point objects

public:
    // Constructors
    Array(); //default constructor
    Array(int size); //allocate by size constructor
    Array(const Array& arr); //copy constructor

    ~Array(); // destructor

    // member operator overloading
    Array& operator = (const Array& arr); // assignment operator overloading
    Point& operator [] (int index); // [] operator
    const Point& operator[](int index) const; // allow for processing const Array object
 
    // getters & setter
    int Size() const; // get size of the array
    void SetElement(int index, const Point& point); // setter
    const Point& GetElement (int index) const; // getter

    };

#endif
