/*
    Shape.cpp

    Implementation of base class Shape. 
    virtual Draw() added.

    2025.3.23
    Ruochen Bao
*/

#ifndef Shape_HPP
#define Shape_HPP

#include <iostream>
using namespace std;

class Shape
{
private:
    int m_id;

public:
    // constructors & destructor
    Shape(); 
    Shape(const Shape& source);
    virtual ~Shape(); // use virtual destructor in base class

    // operator overloading
    Shape& operator = (const Shape& source);

    // to string
    virtual string ToString() const;

    // accessing function
    int ID() const;

    virtual void Draw() const = 0 ;
};

#endif