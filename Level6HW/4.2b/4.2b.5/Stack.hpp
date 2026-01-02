/*
    Stack.hpp

    Header file for a stack class.
    
    2025.3.30
    Ruochen Bao
*/

#ifndef Stack_HPP
#define Stack_HPP

#include "Array.cpp"

template <typename T> class Stack
{
private:
    int m_current;
    Array<T> m_array;

public:
    // constructors;
    Stack();
    Stack(int size);
    Stack(const Stack<T>& source);

    // destructor
    virtual ~Stack();

    // operator overloading
    Stack<T>& operator = (const Stack<T>& source);

    // functionalities
    T Pop();
    void Push(const T& newT);
};

#endif