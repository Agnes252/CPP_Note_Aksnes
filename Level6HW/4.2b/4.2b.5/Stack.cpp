/*
    Stack.cpp

    Implementation of member functions in Stack.hpp

	Modifications:
	2025.3.20 Turn pop() and push() into try...catch block

    2025.3.30
    Ruochen Bao
*/

#ifndef Stack_CPP
#define Stack_CPP

#include "Stack.hpp"
#include "StackException.hpp"

// Constructors
template <typename T>
Stack<T>::Stack() : m_current(0)
{ // Default constructor.
}

template <typename T>
Stack<T>::Stack(int size) : m_current(0), m_array(size)
{
}

template <typename T>
Stack<T>::Stack(const Stack<T>& source) : m_current(source.m_current), m_array(source.m_array)
{ // Copy constructor
}

template <typename T>
Stack<T>::~Stack()
{ // Destructor
}

// assignment operator overloading
template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& source)
{ // Assignment operator
	if (this == &source)
	{
		return *this;
	}

	m_current = source.m_current;
	m_array = source.m_array;

	return *this;
}

// functionalities
template <typename T>
T Stack<T>::Pop()
{
	T t;

	try
	{
		t = m_array[m_current - 1];
	}
	catch (ArrayException& ex)
	{
		throw StackEmptyException();
	}
	m_current--;
	return t;
}

template <typename T>
void Stack<T>::Push(const T& newT)
{
	try
	{
		m_array[m_current] = newT;
	}
	catch (ArrayException& ex)
	{
		throw StackFullException();
	}
	
	m_current++;
}

#endif