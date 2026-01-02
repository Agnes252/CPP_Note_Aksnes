/*
    Stack.hpp

    Header file for a stack class.

    Modifications:
	2025.3.30 Use an int value as template variable.
    
    2025.3.30
    Ruochen Bao
*/

#ifndef Stack_HPP
#define Stack_HPP

#include "Array.cpp"

template <typename T, int size> class Stack
{
private:
    int m_current;
    Array<T> m_array;

public:
    // constructors;
    Stack();
    Stack(const Stack<T, size>& source);

    // destructor
    virtual ~Stack();

    // operator overloading
    Stack<T, size>& operator = (const Stack<T, size>& source);

    // functionalities
    T Pop();
    void Push(const T& newT);
};

#endif