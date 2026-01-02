/*
    ArrayException.hpp

    Base class for array exception.

    2025.3.23
    Ruochen Bao
*/

#ifndef ArrayException_HPP
#define ArrayException_HPP

#include <iostream>
using namespace std;

class ArrayException
{
public:
    // constructor and destructor
    ArrayException()
    {
    }
    
    virtual ~ArrayException()
    {
    }

    // abstract function
    virtual string GetMessage() = 0;

};


#endif