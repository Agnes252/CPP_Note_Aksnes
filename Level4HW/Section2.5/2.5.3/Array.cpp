/*
    Array.cpp

    Implementation of member functions in Array.hpp
    
    2025.3.19
    Ruochen Bao
*/

#include "Point.hpp"
#include "Array.hpp"

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
    if (index >= 0 && index < m_size)
    {
        m_data[index] = point;
    }
}

const Point& Array::GetElement (int index) const
{
    if (index >= 0 && index < m_size)
    {
        return m_data[index];
    }

    return m_data[0];
}

Point& Array::operator [] (int index)
{
    if (index >= 0 && index < m_size)
    {
        return m_data[index];
    }

    return m_data[0];
}

const Point& Array::operator[](int index) const // allow for processing const Array object
{
    if (index >= 0 && index < m_size)
    {
        return m_data[index];
    }

    return m_data[0];
}