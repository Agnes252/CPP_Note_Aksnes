/*
    Array.cpp

    Implementation of member functions in Array.hpp
    Exception handling. (index)

    2025.3.23
    Ruochen Bao
*/

#include "Point.hpp"
#include "Array.hpp"
#include "OutOfBoundsException.hpp"

using namespace std;

Array::Array() : m_data(new Point[10]), m_size(10) // Default constructor
{
}

Array::Array(int size) : m_data(new Point[size]), m_size(size) 
{
}

Array::Array(const Array& arr) : m_size(arr.m_size)
{
    m_data = new Point[arr.m_size];

    for (int i=0; i<m_size; i++)
    {
        m_data[i] = arr.m_data[i]; 
    }
}

Array::~Array() // Default destructor
{
    delete[] m_data;
}

Array& Array::operator = (const Array& arr) // assignment operator overloading
{
    if (this == &arr) return *this;
    
    delete[] m_data;

    m_size = arr.m_size;
    m_data = new Point[m_size];
    
    for (int i=0;i<m_size;i++)
    {
        m_data[i] = arr.m_data[i];
    }

    return *this;
}

int Array::Size() const
{
    return m_size;
}

void Array::SetElement(int index, const Point& point)
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }

    m_data[index] = point;
}

const Point& Array::GetElement (int index) const
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }

    return m_data[index];
}

Point& Array::operator [] (int index)
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }

    return m_data[index];
}

const Point& Array::operator[](int index) const // allow for processing const Array object
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }

    return m_data[index];
}