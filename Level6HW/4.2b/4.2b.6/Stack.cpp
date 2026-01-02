/*
    Stack.cpp

    Implementation of member functions in Stack.hpp

	Modifications:
	2025.3.30 Turn pop() and push() into try...catch block
		Use an int value as template variable.

    2025.3.30
    Ruochen Bao
*/

#ifndef Stack_CPP
#define Stack_CPP

#include "Stack.hpp"
#include "StackException.hpp"

// Constructors
template <typename T, int size>
Stack<T, size>::Stack() : m_current(0), m_array(size)
{ // Default constructor.
}

template <typename T, int size>
Stack<T, size>::Stack(const Stack<T, size>& source): m_current(source.m_current), m_array(source.m_array)
{ // Copy constructor
}

template <typename T, int size>
Stack<T, size>::~Stack()
{ // Destructor
}

// assignment operator overloading
template <typename T, int size>
Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source)
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
template <typename T, int size>
T Stack<T, size>::Pop()
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

template <typename T, int size>
void Stack<T, size>::Push(const T& newT)
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