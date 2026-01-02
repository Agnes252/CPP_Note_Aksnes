/*
    Shape.cpp

    Implementations of shape.hpp

    2025.3.22
    Ruochen Bao
*/

#include "Shape.hpp"
#include <stdlib.h>
#include <sstream>

// default constructor
Shape::Shape() : m_id(rand())
{
}

// copy constructor
Shape::Shape(const Shape& source) : m_id(source.m_id)
{
}

// destructor
Shape::~Shape()
{
}

// assignment operator
Shape& Shape::operator = (const Shape& source)
{
    if (this == &source)
        return *this;
    
    m_id = source.m_id;
    return *this;
}

// to string
string Shape::ToString() const
{
    stringstream stream;
    stream<<"ID:"<<m_id;
    return stream.str();
}

// accessing function
int Shape::ID() const
{
    return m_id;
}

void Shape::Print() const
{
    cout << ToString() << endl;
}