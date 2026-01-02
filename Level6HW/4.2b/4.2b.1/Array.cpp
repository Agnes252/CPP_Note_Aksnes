/*
    Array.cpp

    Implementation of member functions in Array.hpp
    Exception handling. (index)

    2025.3.23
    Ruochen Bao
*/

#ifndef Array_CPP
#define Array_CPP

#include "Array.hpp"
#include "OutOfBoundsException.hpp"


// Static data member.
template <typename T>
int Array<T>::static_m_size = 10;

// constructors
template <typename T>
Array<T>::Array() : m_data(new T[10]), m_size(10) // Default constructor
{
}

template <typename T>
Array<T>::Array(int size) : m_data(new T[size]), m_size(size) 
{
}

template <typename T>
Array<T>::Array(const Array<T>& arr) : m_size(arr.m_size)
{
    m_data = new T[arr.m_size];

    for (int i=0; i<m_size; i++)
    {
        m_data[i] = arr.m_data[i]; 
    }
}

template <typename T>
Array<T>::~Array() // Default destructor
{
    delete[] m_data;
}

// assignment operator
template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& arr) // assignment operator overloading
{
    if (this == &arr) return *this;
    
    delete[] m_data;

    m_size = arr.m_size;
    m_data = new T[m_size];
    
    for (int i=0;i<m_size;i++)
    {
        m_data[i] = arr.m_data[i];
    }

    return *this;
}


template <typename T>
void Array<T>::SetElement(int index, const T& newT)
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }

    m_data[index] = newT;
}

template <typename T>
const T& Array<T>::GetElement (int index) const
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }

    return m_data[index];
}

template <typename T>
T& Array<T>::operator [] (int index)
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }

    return m_data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const // allow for processing const Array object
{
    if (index < 0 || index >= m_size)
    {
        throw OutOfBoundsException(index);
    }

    return m_data[index];
}


// static: DefaultSize
template <typename T>
int Array<T>::DefaultSize()
{
	return static_m_size;
}

template <typename T>
void Array<T>::DefaultSize(int size)
{
	static_m_size = size;
}

#endif